#include<cstdio>
#include<algorithm>
using namespace std;
int a[100010],ans,cnt,flag1,flag2,flag3,flag4,book;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d",&a[i]);
		if(a[i]==4) flag4++;
		if(a[i]==3) flag3++;
		if(a[i]==2) flag2++;
		if(a[i]==1) flag1++;
	}
	ans=flag4+flag2/2+min(flag1,flag3);
	cnt=min(flag3,flag1);
	flag3-=cnt;
	flag1-=cnt;
	flag2%=2;
	if(flag3!=0) ans+=flag3;
	if(flag1!=0) {
		ans+=flag1/4;
		flag1%=4;
	}
	cnt=flag2*2+flag1;
	if(cnt<=4&&cnt!=0) ans++;
	else if(cnt!=0) ans+=2;
	printf("%d\n",ans);
	return 0;
} 
