#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：线段树+标记永久化

const int MAXN = 1e5+5;
struct node{
    int l,r;
    ll val,add;
}tree[MAXN<<2];
ll a[MAXN];
//rt为当前节点，[l,r]为当前区间（建树与常规无差）
void build(int rt,int l,int r) {
    tree[rt].l = l, tree[rt].r = r;
    tree[rt].add = 0;
    if(l==r) {//叶子节点
        tree[rt].val = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(rt*2, l, mid);//左右子树
    build(rt*2+1, mid+1, r);
    tree[rt].val = tree[rt*2].val + tree[rt*2+1].val;
}
//rt为当前节点，[l, r]为对应操作区间，val为操作值
void update(int rt,int l,int r,ll val) {
    int L = tree[rt].l;//当前节点的区间
    int R = tree[rt].r;
    //此时 [l,r] 区间肯定在区间 [L,R] 内
    //则当前节点需更新对应值
    tree[rt].val += (r-l+1)*val;
    //由于后面判断会手动切割区间，所以最后肯定会重合！！！
    if(l==L&&R==r) {//区间重合，直接添加标记，然后返回
        tree[rt].add += val;
        return;
    }
    int mid = (L+R)/2;
    if(r<=mid) update(rt*2, l, r, val);//区间在左子树
    else if(mid<l) update(rt*2+1, l, r, val);//区间在右子树
    else update(rt*2, l, mid, val), update(rt*2+1, mid+1, r, val);
    //将区间[l,r]拆成两个部分：[l,mid]和[mid+1,r]
    //然后分别计算两个子树的值
}
//rt为当前节点，[l,r]为操作区间，mark为标记（对当前节点有贡献）
ll query(int rt, int l, int r, ll mark) {
    int L = tree[rt].l;//当前节点的区间
    int R = tree[rt].r;
    //区间重合，则计算标记对应的贡献和当前值的总和
    //此时mark还没包含当前节点的标记！！！
    if(l==L&&R==r) return (R-L+1)*mark+tree[rt].val;
    int mid = (L+R)/2;
    mark += tree[rt].add;//累加标记
    if(r<=mid) return query(rt*2, l, r, mark);//左子树
    else if(mid<l) return query(rt*2+1, l, r, mark);//右子树
    else return query(rt*2, l, mid, mark)+query(rt*2+1, mid+1, r, mark);
    //分割成两个区间，然后计算左右子树的和
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    build(1, 1, n);
    while(m--) {
        int op,x,y,k;
        cin>>op>>x>>y;
        if(op==1) {
            cin>>k;
            update(1, x, y, k);
        }
        else {
            cout<<query(1, x, y, 0)<<"\n";
        }
    }
    return 0;
}
