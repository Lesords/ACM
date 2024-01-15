#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：线段树+两个lazy标记
//重点是两个标记的计算顺序！！！
//由于 先加后乘 会影响精度，所以采用 先乘后加 的顺序

//例子：
//假设有三个数 a1, a2, a3，共执行三次操作 +2  *3  +4
//1:    t[1].add += 2, t[1].sum = 3*2（3为区间长度
//2:    t[1].mul *= 3
//结果： sum = (a1+2)*3 + (a2+2)*3 + (a3+2)*3
//3:    t[1].add += 4

//如果先加后乘此时结果为：
// sum = (a1+2 +4)*3 + (a2+2 +4)*3 + (a3+2 +4)*3
//     = (a1+2)*3 +4*3 + (a2+2)*3 +4*3 + (a3+2)*3 +4*3
//但是实际结果为：
// sum = (a1+2)*3 +4 + (a2+2)*3 +4 + (a3+2)*3 +4
//两者不等价，若要等价需 /3，如下所示：
// sum = (a1+2 + 4/3)*3 + (a2+2 + 4/3)*3 + (a3+2 + 4/3)*3
//此时为实数运算，会有精度误差
//所以用 先乘后加 的顺序
//注意：区间加操作时，由于 加 对乘没有影响，所以无需修改乘；
//      但是区间乘操作时，需要将 加 的部分乘以对应的值！！！

const int MAXN = 1e5+5;
struct node{
    int l,r;
    ll val,add,mul;//还是要开long long
    //val为总和，add为加标记，mul为乘标记
}tree[MAXN<<2];
int a[MAXN];
int n,m,p;
void build(int rt,int l,int r) {//rt为当前节点，[l,r]为操作区间
    tree[rt].l = l, tree[rt].r = r;//记录对应左右区间
    tree[rt].add = 0, tree[rt].mul = 1;//更新初值
    if(l==r) {//叶子节点，直接更新值
        tree[rt].val = a[l];
        return ;
    }
    int mid = (l+r)/2;//l与L一致，所以也可用l！！！
    build(rt*2, l,mid);//分别建立左右子树
    build(rt*2+1, mid+1, r);
    tree[rt].val = (tree[rt*2].val + tree[rt*2+1].val)%p;//累加左右子树和
}
//rt为当前节点，[l,r]为当前节点的区间，mid为中间点
void push_down(int rt,int l,int r,int mid) {
    int lsiz = mid-l+1;//左子树大小
    int rsiz = r-mid;//右子树大小
    //先乘后加
    //注意：加的时候需要乘以对应子树大小
    tree[rt*2].val = (tree[rt*2].val*tree[rt].mul%p+tree[rt].add*lsiz%p)%p;
    tree[rt*2+1].val = (tree[rt*2+1].val*tree[rt].mul%p+tree[rt].add*rsiz%p)%p;
    //传递乘标记，直接传递即可
    tree[rt*2].mul = (tree[rt*2].mul * tree[rt].mul)%p;
    tree[rt*2+1].mul = (tree[rt*2+1].mul * tree[rt].mul)%p;
    //传递加标记，需要先计算 原来加标记和当前乘标记的贡献，然后累加当前加标记！！
    tree[rt*2].add = (tree[rt*2].add*tree[rt].mul%p + tree[rt].add)%p;
    tree[rt*2+1].add = (tree[rt*2+1].add*tree[rt].mul%p + tree[rt].add)%p;
    tree[rt].add = 0;//赋为初值
    tree[rt].mul = 1;
}
//rt为当前点，[l,r]为操作区间，val为对应值
void update_add(int rt,int l,int r,int val) {
    int L = tree[rt].l;//当前节点左右区间
    int R = tree[rt].r;
    if(l<=L&&R<=r) {//操作区间大于当前节点区间，注意顺序！！！
        tree[rt].val = (tree[rt].val + (R-L+1)*val%p)%p;//添加对应区间长度
        tree[rt].add = (tree[rt].add + val)%p;//加标记
        return;
    }
    int mid = (L+R)/2;//注意区间是[L,R]！！！
    push_down(rt, L, R, mid);
    //与mid判断！！！
    if(l<=mid) update_add(rt*2, l, r, val);//如果有左区间，则继续
    if(r>mid) update_add(rt*2+1, l, r, val);//如果有左区间，则继续
    tree[rt].val = (tree[rt*2].val + tree[rt*2+1].val)%p;//更新区间和
}
//rt为当前点，[l,r]为操作区间，val为对应值
void update_mul(int rt,int l,int r,int val) {
    int L = tree[rt].l;//当前节点左右区间
    int R = tree[rt].r;
    if(l<=L&&R<=r) {//操作区间大于当前节点区间，注意顺序！！！
        tree[rt].val = (tree[rt].val * val)%p;//对应结果，直接乘
        tree[rt].mul = (tree[rt].mul*val)%p;//乘标记
        tree[rt].add = (tree[rt].add*val)%p;//需要额外更新加标记！！！
        //也就是说，加的这部分也需要 *val
        return;
    }
    int mid = (L+R)/2;//注意区间是[L,R]！！！
    push_down(rt, L, R, mid);
    //与mid判断！！！
    if(l<=mid) update_mul(rt*2, l, r, val);//如果有左区间，则继续
    if(r>mid) update_mul(rt*2+1, l, r, val);//如果有左区间，则继续
    tree[rt].val = (tree[rt*2].val + tree[rt*2+1].val)%p;//更新区间和
}
int query(int rt,int l,int r) {
    int L = tree[rt].l;//当前节点左右区间
    int R = tree[rt].r;
    //操作区间大于当前节点区间，注意顺序！！！
    if(l<=L&&R<=r) return tree[rt].val%p;
    int mid = (L+R)/2;//注意区间是[L,R]！！！
    int ans = 0;
    push_down(rt, L, R, mid);
    //判断是否有对应子树，有则计算
    //与mid判断！！！
    if(l<=mid) ans = (ans+query(rt*2, l, r))%p;
    if(r>mid) ans = (ans+query(rt*2+1, l, r))%p;
    return ans;
}
int main() {
    cin>>n>>m>>p;
    for(int i = 1;i <= n;i++) cin>>a[i];
    build(1,1,n);//建树
    while(m--) {
        int op,x,y,k;
        cin>>op>>x>>y;
        if(op!=3) cin>>k;
        if(op==1) {
            update_mul(1, x, y, k);
        }
        else if(op==2) {
            update_add(1, x, y, k);
        }
        else if(op==3) {
            cout<<query(1, x, y)<<"\n";
        }
    }
    return 0;
}
