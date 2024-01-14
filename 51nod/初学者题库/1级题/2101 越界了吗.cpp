#include<iostream>//ac 只能用c++11！！！
//c++中longlong型比较负值会出现问题
using namespace std;
int main() {
	long long a,b;
	cin>>a>>b;
	if(a+b>2147483647||a+b<-2147483648) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
