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
const int MAXN = 1e2+5;
int x[MAXN],y[MAXN];
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n,m,ans = INF;
		cin>>n>>m;
		for(int i = 1;i <= n;i++) {
			cin>>x[i]>>y[i];
			int num = ceil(m*1.0/x[i]);
			ans = min(ans,num*y[i]);
		}
		cout<<ans<<endl;
	}
	return 0;
}
