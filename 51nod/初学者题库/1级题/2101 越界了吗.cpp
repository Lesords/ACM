#include<iostream>//ac ֻ����c++11������
//c++��longlong�ͱȽϸ�ֵ���������
using namespace std;
int main() {
	long long a,b;
	cin>>a>>b;
	if(a+b>2147483647||a+b<-2147483648) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
