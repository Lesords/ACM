#include<iostream>//ac
using namespace std;
int main() {
	int T,n;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=1;i<=n*3;i++) {//n*3 ÐÐ
			for(int j=1;j<=n;j++) cout<<"HDU";//n ÁÐ
			cout<<endl;
		}
	}
	return 0;
} 
