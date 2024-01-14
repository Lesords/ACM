#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
	int t,tmp;
	scanf("%d",&t);
	while(t--) {
		long long ans = 1;
		scanf("%d",&tmp);
		for(int i = 2;i * i <= tmp;i++) {//i * i是边界
			if(tmp%i==0) {
				ans += i;
				if(tmp/i != i)  ans += tmp/i;//两个因数不同
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
