#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
vector<int> g[MAXN];
int main() {
	fast;
	int t;
	cin>>t;
	for(int i = 1;i <= t;i++) {
		int n,m;
		cin>>n>>m;
		for(int j = 1;j <= n;j++) g[j].clear();
		for(int j = 1;j <= n;j++) {
			int num,tmp;
			cin>>num;
			while(num--) {
				cin>>tmp;
				g[j].push_back(tmp);
			}
		}  
		cout<<"Case #"<<i<<": \n";
		for(int j = 1;j <= m;j++) {
			int s,num,tmp;
			cin>>s>>num;
			bool ok = 1;
			for(int k = 1;k <= num;k++) {
				cin>>tmp;
				if(ok==0) continue;
				if(g[s].size()<tmp) {
					ok = 0;
					continue;
				}
				s = g[s][tmp-1];
			}
			if(ok==0) cout<<"Packet Loss";
			else cout<<s;
			
			if(i==t&&j==m) continue;
			cout<<"\n";
		}
	}
	return 0;
}