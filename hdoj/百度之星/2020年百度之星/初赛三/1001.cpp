#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
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
double b[105],c[105];
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		double ans = 0;
		for(int i = 1;i <= n;i++) {
			cin>>b[i]>>c[i];
			c[i] = 1-c[i];
			ans = max(ans,c[i]/(b[i]+c[i]));
		}
		printf("%.5f\n",ans);
	}
	return 0;
}
