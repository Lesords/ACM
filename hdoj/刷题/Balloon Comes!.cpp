#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
	int t;
	cin>>t;
	while(t--) {
		char op;
		int a,b;
		cin>>op>>a>>b;
		if(op == '+') cout<<a+b<<endl;
		else if(op == '-') cout<<a-b<<endl;
		else if(op == '*') cout<<a*b<<endl;
		else {
			if(a%b==0) cout<<a/b<<endl;//非整数输出两个小数点
			else printf("%.2f\n",a*1.0/b*1.0);
		}
	}
	return 0;
}
