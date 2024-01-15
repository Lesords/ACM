#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题意：给定总天数n和最大周期数r，问有多少中不同类型的填涂方案（相连）
//题解：若周期数r<总天数n，那么每种周期数中的不同类型为周期数r(1,2,3,···,r)
//若周期数>=总天数，那么总共只有一种情况（可平移得到之后所有情况）

int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,r;
        cin>>n>>r;
        if(r==1) cout<<"1\n";//周期数为1，特判
        else {
            ll res = 0;//多余的（周期数大于总天数时）
            if(r>=n) r = n-1,res = 1;//修改r
            cout<<(1+r)*r/2+res<<endl;//等差求和
        }
    }
	return 0;
}
