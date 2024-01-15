#include<iostream>//wa
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
inline char gch()
{
    static char buf[100010], *h = buf, *t = buf;
    return h == t && (t = (h = buf) + fread(buf, 1, 100000, stdin), h == t) ? EOF : *h ++;
}
template<class T>
inline void re(T &x)
{
    x = 0;
    char a; bool b = 0;
    while(!isdigit(a = gch()))
        b = a == '-';
    while(isdigit(a))
        x = (x << 1) + (x << 3) + a - '0', a = gch();
    if(b == 1)
        x *= -1;
}
const int MAXN = 1e5+5;
int a[MAXN],dp[MAXN][2];
int main() {
	int t,n;
	re(t);
	while(t--) {
		re(n);
		for(int i = 1;i <= n;i++) re(a[i]),dp[i][0]=dp[i][1] = -INF;
		dp[1][0] = dp[1][1] = a[1];
		for(int i = 2;i <= n;i++) {
			if(!a[i]) {
				dp[i][1] = 0,dp[i][0] = max(dp[i-1][1]+a[i],dp[i-1][0]+a[i]);
			}
			else {
				dp[i][0] = max(dp[i-1][1]+a[i],dp[i-1][0]+a[i]);
				dp[i][1] = max(dp[i-2][1]+a[i-1]*a[i],dp[i-2][0]+a[i-1]*a[i]);
			}
		}
		printf("%d\n",max(dp[n][0],dp[n][1]));
	}
	return 0;
}
