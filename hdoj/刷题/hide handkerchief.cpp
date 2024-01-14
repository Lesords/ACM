#include<iostream>//ac
using namespace std;
int gcd(int a,int b) {
	return a%b==0?b:gcd(b,a%b);
}
int main() {
	int a,b;
	//判断相应的间隔是否可以找到手帕其实就是判断最大公因数
	while(cin>>a>>b) {
		if(a==-1&&b==-1) break;
		if(gcd(a,b)!=1) cout<<"POOR Haha"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
} 
