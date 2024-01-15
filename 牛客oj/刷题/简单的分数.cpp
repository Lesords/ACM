#include<iostream>//ac
#include<cmath>
using namespace std;
int gcd(int a,int b) {
	return a%b==0?b:gcd(b,a%b);
}
void solve(int a, int b) {
	int flag = 0;
	int cmn = gcd(a,b);//最后结果中的 分母分子 公因数
	if(a*b<0) flag = 1;//需要负号
	a = abs(a), b = abs(b);
	if(flag) cout<<"-";//需要特别处理负号
	cout<<abs(a/cmn)<<"/"<<abs(b/cmn)<<endl;
}
int main() {
	int t,op;
	cin>>t;
	while(t--) {
		int a,b,c,d;
		cin>>op>>a>>b>>c>>d;
		int down = b*d;//直接算即可，gcd最后判断即可
		if(op) {
			int up = a*d + c*b;
			solve(up,down);
		}
		else {
			int up = a*d - c*b;
			solve(up,down);
		}
	}
	return 0;
}
