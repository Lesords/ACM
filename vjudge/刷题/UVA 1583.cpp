#include<stdio.h>//ac 生成元
#include<string.h> 
#define maxn 100005
int ans[100010];//数组越界

int main() {
	int T, n;
	memset(ans, 0, sizeof(ans));
	for(int m = 1; m < maxn; m++) {
		int x = m, y = m;
		while(x) y += x % 10, x /= 10;
		if(!ans[y] || m < ans[y]) ans[y] = m;
	}
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		printf("%d\n", ans[n]);
	}
	return 0;
}
