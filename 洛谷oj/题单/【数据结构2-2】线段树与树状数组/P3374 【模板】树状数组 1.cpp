#include<iostream>//ac
#include<algorithm>
#define lowbit(a) (a)&(-a)
using namespace std;

//题解：树状数组模板题
//怎么输入一个数字val相当于在该位置添加val
//然后利用前缀和查询区间值

const int MAXN = 5e5+5;
int a[MAXN],tree[MAXN];
int n,m;
void add(int pos,int val) {//将pos位置的值增加val
    while(pos<=n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
int ask(int pos) {//查询[1,pos]的值
    int ans = 0;
    while(pos>=1) {
        ans += tree[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i],add(i,a[i]);
    while(m--) {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1) add(x,y);
        else cout<<ask(y)-ask(x-1)<<"\n";
    }
    return 0;
}
