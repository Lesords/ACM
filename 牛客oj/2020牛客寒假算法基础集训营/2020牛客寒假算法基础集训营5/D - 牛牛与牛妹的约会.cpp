#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
int main() {
	int t;
	double a,b,ans;
	scanf("%d",&t);
	while(t--) {
		scanf("%lf%lf",&a,&b);
		ans = 0;
		if(a>=b) {
			int flag = 1;
			while(1) {
				flag = (a<0)?-1:1;
				double change = pow(fabs(a),1.0/3.0)*flag;
				if(a-change>1&&change>b)
					ans++,a = change;
				else break;
			}
			flag = (a<0)?-1:1;
			ans += min(a-b,1+fabs(b-pow(fabs(a),1.0/3.0)*flag));
		}
		else {
			int flag = 1;
			while(1) {
				flag = (a<0)?-1:1;
				double change = pow(fabs(a),1.0/3.0)*flag;
				if(change-a>1&&change<b)
					ans++,a = change;
				else break;
			}
			flag = (a<0)?-1:1;
			ans += min(b-a,1+fabs(pow(fabs(a),1.0/3.0)*flag-b));
		}
		printf("%.9f\n",ans);
	}
	return 0;
}
