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

//题意:除2或除6多少次可以为1，否则输出-1

int main() {
	int t;
	ll n;
	cin>>t;
	while(t--) {
		cin>>n;
		ll ans = 0,flag = 0;//初始化为0
		if(n==1) cout<<'0'<<endl;//1直接输出即可
		else {
			while(n!=1) {
				while(n%6==0) ans++,n/=6;//可以被6除
				if(n==1) break;//为1结束
				//如果可以被3除，那么*2之后即可被6除
				if(n%3==0) n*=2,ans++;
				else {//否则说明无解
					flag = 1;break;
				}
			}
			if(flag) cout<<"-1"<<endl;
			else cout<<ans<<endl;
		}
	}
	return 0;
}
