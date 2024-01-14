#include<iostream>
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
const int MAXN = 1e5+5;
int vis[11];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		string tmp;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			vis[tmp[4]-'0']++;
		}
		int ans = 0;
		for(int i = 0;i <= 4;i++) {
			ans = max(ans,n-vis[i]-vis[9-i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
