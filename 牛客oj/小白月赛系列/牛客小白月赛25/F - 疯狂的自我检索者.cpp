#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<algorithm>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
double ans,tmp;
int main() {
	int n,m;
	cin>>n>>m;
	for(int i = 1;i <= (n-m);i++) {
		cin>>tmp,ans += tmp;
	}
	//小就是1，大就是5
	printf("%.5f %.5f\n",(ans+m)/n,(ans+5*m)/n);
	return 0;
}
