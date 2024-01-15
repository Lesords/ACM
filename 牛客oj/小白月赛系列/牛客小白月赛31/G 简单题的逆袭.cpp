#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
ll solve(ll x,ll y) {//乘会爆ll，那么可以把大的数拿去除！！！
    ll ans = 1;
    while(x<=y) {//x*x 类似于 y/x
        y /= x;//除的结果也是一样的！！！
        ans++;
    }//ans表示x>y的值
    return ans-1;//所以需减1
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll x,y;
        cin>>x>>y;//y==0!!!
        if(x<=1||y==0) cout<<"-1\n";//不存在的情况
        else {
            cout<<solve(x,y)<<"\n";
        }
    }
    return 0;
}
