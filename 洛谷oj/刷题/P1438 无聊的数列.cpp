#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：线段树
//利用线段树来存储原数组的差分值
//那么对于区间 [l,r] 添加一个等差数列 k+0, k+d, k+2d, k+3d···而言
//则有：
//1. 对 l 位置单点添加k（因为当前值多了k）
//2. 对 (l, r) 范围内的进行区间操作，增加d（因为这个范围内，每个数都比前面一个数多k）
//3. 对 r+1 位置进行单点修改，减去 k+(l-r)*d（即减去原数组中对应等差数列的最后一个数值）
//也就是说，可以转换成两个单点修改和一个区间修改
//注意判断位置是否有贡献！！！
//注意：变量名别写错了！！！

const int MAXN = 1e5+5;
struct node{
    int l, r;
    ll val, add;
}tree[MAXN<<2];
ll a[MAXN],d[MAXN];//a为原数组，d为差分数组
//当前节点为rt，[l,r]为操作区间
void build(int rt,int l,int r) {
    tree[rt].l = l, tree[rt].r = r;//更新当前节点对应信息
    tree[rt].add = 0;
    if(l==r) {//叶节点，直接更新值，然后返回
        tree[rt].val = d[l];
        return ;
    }
    int mid = (l+r)>>1;
    build(rt<<1, l, mid);//分别建立左右子树
    build(rt<<1|1, mid+1, r);
    tree[rt].val = tree[rt<<1].val + tree[rt<<1|1].val;//更新值
}
//当前节点为rt，[l,r]为当前节点的区间范围，mid为中间点
void push_down(int rt,int l,int mid,int r) {//传递标记
    if(tree[rt].add) {
        //更新对应左右子树的值
        tree[rt<<1].val += (mid-l+1)*tree[rt].add;
        tree[rt<<1|1].val += (r-mid)*tree[rt].add;
        //将标记传递到对应的左右子树
        tree[rt<<1].add += tree[rt].add;//传递标记！！！
        tree[rt<<1|1].add += tree[rt].add;
        tree[rt].add = 0;//将当前标记更新为0
    }
}
//当前节点为rt，[l,r]为操作区间，val为对应操作值
void update(int rt,int l,int r,ll val) {
    int L = tree[rt].l;//当前节点的区间
    int R = tree[rt].r;
    if(l<=L&&R<=r) {//覆盖当前节点整个区间
        tree[rt].val += (R-L+1)*val;//添加对应值，注意是添加！！！
        tree[rt].add += val;//添加标记
        return;
    }
    int mid = (L+R)>>1;
    push_down(rt, L, mid, R);//向下传递标记
    if(l<=mid) update(rt<<1, l, r, val);//判断左右子树是否有交集，有则更新
    if(r>mid) update(rt<<1|1, l, r, val);
    tree[rt].val = tree[rt<<1].val + tree[rt<<1|1].val;//更新值
}
//当前节点为rt，[l,r]为操作区间
ll query(int rt,int l,int r) {
    int L = tree[rt].l;//当前节点区间
    int R = tree[rt].r;
    if(l<=L&&R<=r) {//覆盖当前节点区间，直接返回
        return tree[rt].val;
    }
    int mid = (L+R)>>1;
    ll ans = 0;
    push_down(rt, L, mid, R);//向下传递标记
    if(l<=mid) ans += query(rt<<1, l, r);//计算对应左右子树的值
    if(r>mid) ans += query(rt<<1|1, l, r);
    return ans;
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        d[i] = a[i]-a[i-1];//计算差分
    }
    build(1, 1, n);//初始化建树
    while(m--) {
        int op,l,r;
        ll k,d;
        cin>>op;
        if(op==1) {
            cin>>l>>r>>k>>d;
            update(1, l, l, k);//首位置+k， [l,l]即为单点修改
            if(l+1<=r) update(1, l+1, r, d);//l+r<=r时，才有对应的区间
            if(r+1<=n) update(1, r+1, r+1, -(k+(r-l)*d));//超过范围，无需更新
            //因为查询操作是求差分的前缀和，与后面的值无关
        }
        else {
            cin>>l;
            cout<<query(1, 1, l)<<"\n";//前缀和即为原来的值
        }
    }
    return 0;
}
