#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n,m;
	double a[105];
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>m;
		for(int j=1;j<=m;j++) {
			cin>>a[j];
		}
		sort(a+1,a+1+m);
		printf("%.2f\n",a[m]);
	}
	return 0;
}
