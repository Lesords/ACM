#include<iostream>//ac
using namespace std;
int a[12][12];
int main() {
	for(int i=1;i<=11;i++) a[i][1] = a[1][i] = 1;
	for(int i=2;i<=11;i++)
		for(int j=2;j<=11;j++)
			a[i][j] = a[i-1][j] +a[i][j-1];//Ô¤´¦Àí
	int n,maxx = 1;
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]>maxx) maxx = a[i][j];
	cout<<maxx<<endl;
	return 0;
} 
