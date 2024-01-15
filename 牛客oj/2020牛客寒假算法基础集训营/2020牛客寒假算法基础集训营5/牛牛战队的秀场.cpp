#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#define ll long long
#define PI acos(-1.0)
using namespace std;
int main() {
	double n,r,i,j;
	cin>>n>>r>>i>>j;
	double dis = r*(sqrt(2.0-2.0*(cos(2.0*PI/n))));
	if(i>j) {
		double t = i;
		i = j,j = t;
	}
	double ans = dis*min(j-i,n-j+i);
	printf("%.6f",ans);
	return 0;
}
