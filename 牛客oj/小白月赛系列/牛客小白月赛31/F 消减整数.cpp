#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：每个过程可以理解为减去一个数k，然后每次都会剩余rest的值
//那么也就是说，可以转换为每次添加rest的值，几次后可以被 序列后一个数 整除

ll cal(ll n) {//计算够减的数（删减序列最后一位的值）
    ll l = 1,r = n,ans = 0;//ans值尽量取大
    while(l<=r) {
        ll mid = (l+r)>>1;
        //减去的总和用等差数列求和公式
        if((1+mid)*mid/2<=n) ans = mid,l = mid+1;//偏小，则右移
        else r = mid-1;
    }
    return ans;
}
ll gcd(ll a,ll b) {//最小公倍数
    return a%b==0?b:gcd(b,a%b);
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n;cin>>n;
        ll val = cal(n);//够减的数
        ll rest = n-(1+val)*val/2;//剩余的值
        if(rest==0) cout<<"1\n";//刚好减完则只需要一次
        else cout<<((val+1)/gcd(val+1,rest))<<"\n";//lcm(val+1,rest)/rest
        //否则需要的值则必须为 rest 的倍数，且可以被 (val+1) 整除
        //即为 lcm(val+1,rest)/rest （次数），可推为gcd如上
    }
    return 0;
}
