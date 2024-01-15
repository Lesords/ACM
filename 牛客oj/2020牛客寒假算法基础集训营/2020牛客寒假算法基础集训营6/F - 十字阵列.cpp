#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
const int MOD = 1e9 + 7;
const int MAXN = 2005;
ll n,m,h,ans,x,y,z;
ll map[2005][2005];
int main() {
	scanf("%lld%lld%lld",&n,&m,&h);
	for(int i = 1;i <= h;i++) {
		scanf("%lld%lld%lld",&x,&y,&z);
		ll num = ((1+n)*n/2+(1+m)*m/2+x*(m-1)+y*(n-1))%MOD;
		ans = (ans+num*z)%MOD;
		
		//for(int j = 1;j <= m;j++) map[x[i]][j] += z;
		//for(int j = 1;j <= n;j++) map[j][y] += z;
		//map[x][y] -= z;
	}
	/*for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			//cout<<map[i][j]<<' ';
			int tmp = map[i][j]*(i+j)%MOD;
			ans = (ans+tmp)%MOD;
		}
		//cout<<endl;
	}*/
	printf("%lld",ans);
	return 0;
}
