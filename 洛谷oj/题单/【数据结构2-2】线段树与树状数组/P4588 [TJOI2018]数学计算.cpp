#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：常规线段树
//将q次操作，转换成区间跨度为q的线段树
//每次操作都是对线段树中的叶子节点进行操作，即单点修改
//对于 1 操作直接修改 对应操作次数对应的位置 的值
//对于 2 操作修改 给定位置 的值

const int MAXN = 1e5+5;
struct node{
    int l,r;
    ll val;//还是需要longlong
}tree[MAXN<<2];
int q,m;
void build(int rt,int l,int r) {//建树，[l,r]为对应区间
    tree[rt].l = l, tree[rt].r = r;
    if(l==r) {//叶子节点，更新值
        tree[rt].val = 1%m;
        return ;
    }
    int mid = (l+r)/2;
    build(rt*2, l, mid);//分别建立左右子树
    build(rt*2+1, mid+1, r);
    tree[rt].val = tree[rt*2].val*tree[rt*2+1].val%m;
}
void update(int rt,int pos,int val) {//将pos位置的值修改为val
    int L = tree[rt].l;//当前节点的区间
    int R = tree[rt].r;
    if(L==R) {//若为叶子节点，即为所需要修改的节点
        tree[rt].val = val%m;
        return;
    }
    int mid = (L+R)/2;
    //判断pos在哪个子树，修改对应的子树
    if(pos<=mid) update(rt*2, pos, val);
    else update(rt*2+1, pos, val);
    tree[rt].val = tree[rt*2].val * tree[rt*2+1].val % m;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>q>>m;
        build(1, 1, q);
        for(int i = 1;i <= q;i++) {
            int op,x;
            cin>>op>>x;
            if(op==1) {
                update(1, i, x);
            }
            else update(1, x, 1);
            //根节点即为最终值
            cout<<tree[1].val%m<<"\n";
        }
    }
    return 0;
}
