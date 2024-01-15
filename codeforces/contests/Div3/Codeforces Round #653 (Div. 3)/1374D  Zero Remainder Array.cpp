#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题意：初始x=0，每次有两个操作
//选择一个数+x,并且x++；   x++
//所以由此可知步骤数到最后就是x的值

//题解：对于每个数都需要组成k的倍数，所以先%k存储
//然后判断每个数需要 加多少 成为k的倍数
//由于x在加的过程中，每个数只会出现一次，
//所以对每个相同的a[i](加的值)都需要多加n次k的值
//那么最大的值就是 k*(num[a[i]]-1)+a[i]
//因为第一个不需要加 k，所以需-1

int main() {
	int t,n,k;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d",&n,&k);
		map<int,int> ma;
		int flag = 0,tmp;
		ll ans = 0;
		for(int i = 1;i <= n;i++) {
			scanf("%d",&tmp);
			tmp %= k;
			if(tmp) {
				if(!flag) flag = 1;
				ma[k-tmp]++;//记录k-tmp的数量
			}
		}
		if(!flag) {//已经满足，无需操作
			printf("0\n");
			continue;
		}
		for(auto num:ma) {
			//取最大值
			ans = max(ans,num.fi*1LL+(num.se-1)*1LL*k);
		}
		//ans需要操作的最大值，操作完之后需+1才为总数
		printf("%lld\n",ans+1);
	}
	return 0;
}
