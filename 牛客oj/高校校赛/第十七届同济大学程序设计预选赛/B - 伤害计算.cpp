#include<iostream>//wa
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 1005;
double a[MAXN];
int main() {
	for(int i = 1;i < MAXN;i++) {
		a[i] = 1.0/i*1.0;
	}
	string s;
	getline(cin,s);
	int num = 0,val = 0;
	double ans = 0;
	int flag = 0;
	for(int i = 0;i < s.size();i++) {
		if(s[i]=='+'||i==s.size()-1) {
			if(i==s.size()-1&&s[i]!='+') {
				int tmp = s[i]-'0';
				if(flag) val = val*10 + tmp;
				else num = num*10 + tmp;
			}
			if(flag==0) ans += num;
			else {
				double tmp = 0;
				/*for(int i = 1;i <= val;i++) {
					tmp += i*a[val];
				}*/
				tmp = (1+val)/2.0*val*a[val];
				ans += num*tmp*1.0;
			}
			num = val = flag = 0;
		}
		else if(s[i]=='d') flag = 1;
		else if(flag==0) {
			if(s[i]<'0'||s[i]>'9') continue;
			int tmp = s[i]-'0';
			num = num*10+tmp;
		}
		else {
			if(s[i]<'0'||s[i]>'9') continue;
			int tmp = s[i]-'0';
			val = val*10+tmp;
		}
	}
	if(ceil(ans)==ans) cout<<ans;
	else printf("%.1f",ans);
	return 0;
}
