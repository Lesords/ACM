#include<iostream>//ac
#include<string>
using namespace std;
char a[20] ={'0','1','2','3','4','5','6','7','8',
'9','A','B','C','D','E','F'};
string f(int n,int sys) {
	string ans;
	int flag = 0;
	if(n<0) flag = 1,n = -n;//负数
	while(n) {
		ans = a[n%sys] + ans;
		n /= sys;
	}
	if(flag) return '-' + ans;//加负号
	return ans;
}
int main() {
	int n,m;
	while(cin>>n>>m) {
		if(n==0) cout<<"0"<<endl; 
		else cout<<f(n,m)<<endl;
	}
	return 0;
}
