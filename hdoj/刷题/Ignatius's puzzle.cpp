#include<iostream>//ac
using namespace std;
int main() {
	int n;
	while(cin>>n) {
		int flag = 0;
		for(int i=1;i<65;i++) {
			if(!((18+n*i)%65)) cout<<i<<endl,flag=1;//65Ϊһ������
			if(flag) break;
		}
		if(!flag) cout<<"no"<<endl;
	}
	return 0;
}
