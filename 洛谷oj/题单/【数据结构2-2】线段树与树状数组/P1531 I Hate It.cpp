#include<iostream>//ac
#include<algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

//题解：树状数组求区间最大值
//树状数组的每个节点x，存储的是 [x-lowbit(x)+1, x] 范围内的最大值

const int MAXN = 2e5+5;
int n,m;
int tree[MAXN],a[MAXN];
int lowbit(int x) { return (x)&(-x); }
void add(int pos,int val) {//将pos位置修改为val
    a[pos] = val;//原数组只有pos位置才需要修改
    while(pos<=n) {
        tree[pos] = a[pos];//取所有对pos有贡献的位置取max！！！
        int siz = lowbit(pos);//siz即为当前pos的区间大小
        for(int i = 1;i < siz;i <<= 1) {//i不能超过siz大小
            tree[pos] = max(tree[pos], tree[pos-i]);//pos-i即为对pos有贡献的位置
        }
        pos += siz;
    }
}
int ask(int l,int r) {//查询[l,r]区间内的最大值
    int ans = 0;
    while(l<=r) {//若还存在区间
        ans = max(ans, a[r]);//取右边界
        r--;//右边界前移
        while(r-lowbit(r)>=l) {//如果r的区间不会越过l（即大于等于l）
            ans = max(ans, tree[r]);//则r位置存在贡献
            r -= lowbit(r);//缩小右区间
        }
    }
    return ans;
}
int main() {
    fast;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        add(i, a[i]);//初始化，其实可能一个个单点修改
    }
    while(m--) {
        char op;
        int x,y;
        cin>>op>>x>>y;
        if(op=='Q') {
            cout<<ask(x,y)<<"\n";
        }
        else {
            if(a[x]<y) {//小于y才需要修改！！！
                add(x, y);
            }
        }
    }
    return 0;
}
