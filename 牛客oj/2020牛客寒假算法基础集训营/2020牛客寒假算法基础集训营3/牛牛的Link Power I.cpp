#include<iostream>//wa
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;
ll book[MAXN],ans[MAXN];
int main() {
	int n,cnt = 1;
	char ch;
	scanf("%d",&n);
	getchar();
	for(int i = 1;i <= n;i++) {
		scanf("%c",&ch);
		if(ch=='1') {
			if(cnt!=1) {
				ans[i] = (ans[book[cnt-1]]*2)%MOD+((cnt-1)*(i-book[cnt-1]))%MOD;
				ans[i] %= MOD;
			}
			book[cnt++] = i;
		}
	}
	printf("%d",ans[book[cnt-1]]%MOD);
	return 0;
}
