#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[505]; 
int main() {
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--) {
		int n,area,flag=0;
		memset(a,0,sizeof(a));
		cin>>n;
		for(int i=0;i<n;i++) {
			cin>>a[4*i+1]>>a[4*i+2]>>a[4*i+3]>>a[4*i+4];
		}//�������
		sort(a+1,a+4*n+1);//����
		area=a[1]*a[4*n];//��׼���
		for(int i=1;i<=n;i++) {//������Ȳ������Ϊarea
			if(a[2*i-1]!=a[2*i]||a[4*n-2*i+1]!=a[4*n-2*i+2]||
			a[2*i-1]*a[4*n-2*i+2]!=area) {
				flag=1;
				break;
			}
		}
		puts(flag?"NO":"YES");
	}
	return 0;
} 
