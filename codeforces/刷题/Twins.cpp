#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(const int &x, const int &y) {	return x > y;
}
int a[105],sum,cnt,ans,n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) {
		cnt+=a[i];
		if(cnt>sum-cnt){
			ans=i;
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
