#include<iostream>
using namespace std;
long long a,b,c;
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>a>>b;
		c=a&b;//ȡa��b�����ж��е�1������������лὫ1תΪ0 
		if(c==0) cout<<"1"<<endl;
		else cout<<c<<endl;
	}
	return 0;
}
