#include<iostream>//ac
using namespace std;
bool judge(int n) {
	while(n>1) {//为1则说明可以除尽
		if(n%5==0) n /= 5;
		else if(n%2==0) n /= 2;
		else return false;
	}
	return true;
}
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		if(judge(n)) cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	return 0;
}
