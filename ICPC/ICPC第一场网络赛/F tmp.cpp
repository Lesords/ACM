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
#define eps 1e-5
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
double getd(double a, double b,double c, double d) {
	double x = abs(a-c);
	double y = abs(b-d); 
	return (double) sqrt(x*x + y*y);
}
int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1;i <= t;i++) {
		printf("Case #%d: ", i);
		double a, b, r;
		cin>>a>>b>>r;
		
		double ans = getd(a, max(b-r, 0.0), 0, 0);//下方
		ans *= 2;
		ans -= r;
	
		printf("%.2f", ans);
		if(i!=t) printf("\n");
	}
	return 0;
}