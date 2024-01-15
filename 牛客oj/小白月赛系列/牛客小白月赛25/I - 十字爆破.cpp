#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 1e6+1e5;
ll a[MAXN],col[MAXN],row[MAXN],ans,tmp,cnt;
inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}
int main() {
	int n,m;
	n = read();
	m = read();
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			tmp = read();
			a[++cnt] = tmp;
			col[j] += tmp;
			row[i] += tmp;
		}
	}
	cnt = 1;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(j!=1) printf(" ");
			ans = row[i]+col[j]-a[cnt++];
			printf("%lld",ans);
		}
		printf("\n");
	}
	return 0;
}
