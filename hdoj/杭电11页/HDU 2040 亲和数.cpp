#include<iostream>
using namespace std;
int f(int a,int b) {
	int sum = 1;//初始为1 
	for(int i=2;i<=a/2;i++) {//对半找因子 
		if(!(a%i)) sum += i;
	}
	if(sum == b) return true;
	return false;
}
int main() {
	int T,a,b;
	cin>>T;
	while(T--) {
		cin>>a>>b;
		if(f(a,b)&&f(b,a)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
