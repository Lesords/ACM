#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
double a[20],b[20],m;
bool cmp(int a,int b) {
	return a>b;
}
int main() {
	int n,flag = 0;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		b[i] = a[i];
	}
	if(a[9]>=0.8*m) flag = 1;
	sort(a+1,a+1+n,cmp);
	if(b[9]>=a[3]) flag = 1;
	cout<<(flag?"Yes":"No");
	return 0;
}
