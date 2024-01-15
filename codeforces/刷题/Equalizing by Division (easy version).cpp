#include<iostream>
#include<cstring>
#include<algorithm>
#define INF 999999
using namespace std;
const int maxn=2e5+5;
int a[55],cnt[maxn],num[maxn];
int main() {
	int n,k,ans=INF;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) {
		int tmp=0;
		int x=a[i];
		while(x) {
			cnt[x]++;//用来记录x的数量
			num[x]+=tmp;//用来计算转为x的操作数
			if(cnt[x]==k) {//x的数量满足要求
				ans=min(ans,num[x]);//取小
				break;
			}
			tmp++;
			x/=2;
		}
	}
	cout<<ans<<endl;
	return 0;
}
