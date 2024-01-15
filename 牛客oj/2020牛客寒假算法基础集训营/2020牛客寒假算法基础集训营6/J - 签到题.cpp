#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
double a[4],R[4],sum;
int main() {
	int flag = 0;
	for(int i = 1;i <= 3;i++) cin>>a[i],sum+=a[i];
	sort(a+1,a+4);
	if(a[1]+a[2]<=a[3]) {
		cout<<"wtnl";return 0;
	}
	R[2] = (a[1]-a[2]+a[3])/2.0;
	R[1] = a[1]-R[2];
	R[3] = a[3]-R[2];
	sort(R+1,R+4);
	if(R[1]>0&&R[2]>0&&R[3]>0&&(R[1]+R[2]+R[3])*2==sum) {
		cout<<"Yes\n";
		for(int i = 1;i <= 3;i++) {
			printf("%.2f%c",R[i],i!=3?' ':'\n');
		}
	}
	else cout<<"No";
	return 0;
}
