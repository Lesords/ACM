#include<iostream>//ac
using namespace std;
int main() {
	int t,x,y;
	cin>>t;
	while(t--) {
		cin>>x>>y;//x>3ʱ������ת��Ϊ��������
		if(x==y||x>3||x>y) cout<<"YES"<<endl;
		else if(x*3==y*2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
