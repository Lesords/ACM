#include<iostream>//wa
#include<cstdio>
#include<cstring>
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
int vis[MAXN];
string s[MAXN];
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,a,b,c,ans = 0;
		cin>>n>>a>>b>>c;
		for(int i = 1;i <= n;i++) {
			cin>>s[i];
		}
		sort(s+1,s+n+1);
		for(int i = 1;i <= n;i++) {
			if(s[i][0]=='0') {
				if(a) a--,ans+=3;
				else continue;
			}
			else if(s[i][0]=='1') {
				if(b) b--,ans+=3;
				else continue;
			}
			else {
				if(c) c--,ans+=3;
				else continue;
			}
			vis[i] = 1;
		}
		for(int i = 1;i <= n;i++) {
			if(vis[i])  continue;
			if(s[i][1]=='0') {
				if(a) a--,ans+=2;
				else continue;
			}
			else if(s[i][1]=='1') {
				if(b) b--,ans+=2;
				else continue;
			}
			else {
				if(c) c--,ans+=2;
				else continue;
			}
			vis[i] = 1;
		}
		for(int i = 1;i <= n;i++) {
			if(vis[i]) {
				vis[i] = 0;
				continue;
			}
			if(s[i][2]=='0') {
				if(a) a--,ans+=1;
				else continue;
			}
			else if(s[i][2]=='1') {
				if(b) b--,ans+=1;
				else continue;
			}
			else {
				if(c) c--,ans+=1;
				else continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
