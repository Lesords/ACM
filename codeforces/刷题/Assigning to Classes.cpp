#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN];
int main() {
	int t,n;
	scanf("%d",&t);//���������󣬿���scanf
	while(t--) {
		scanf("%d",&n);
		for(int i = 1;i <= 2*n;i++) scanf("%d",a+i);
		sort(a+1,a+2*n+1);
		printf("%d\n",a[n+1]-a[n]);
		//Ҫ�����������λ�����С����ôȡ�м�����������
	}
	return 0;
}
