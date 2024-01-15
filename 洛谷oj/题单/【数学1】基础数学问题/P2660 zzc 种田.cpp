#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：将矩形尽量分成正方形，若有不满足的则继续递归计算
//可画图理解

ll solve(ll a,ll b) {
    if(a<b) swap(a,b);//令a为长b为宽
    ll ans = 0;
    ans += b*4*(a/b);//可以分成 (a/b) 个长为b的正方形(周长为4b)
    if(a%b) ans += solve(b,a%b);//若有多余部分，递归计算（b为长，a%b为宽
    return ans;
}
int main() {
    ll a,b;
    cin>>a>>b;
    cout<<solve(a,b);
    return 0;
}
