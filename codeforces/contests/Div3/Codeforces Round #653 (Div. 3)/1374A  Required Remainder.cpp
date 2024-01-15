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
int main() {
	int t;
	ll x,y,n;
	cin>>t;
	while(t--) {
		cin>>x>>y>>n;//x的倍数+y
		ll tmp = n/x;//n的范围内k最大
		if(tmp*x+y<=n) cout<<tmp*x+y<<endl;
		else cout<<(tmp-1)*x+y<<endl;//若超过n
	}
	return 0;
}
