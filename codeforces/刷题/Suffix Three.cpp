#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	int t;
	cin>>t;
	string tmp;
	while(t--) {
		cin>>tmp;
		char judge = tmp[tmp.size()-1];
		if(judge == 'o') cout<<"FILIPINO"<<endl;
		else if(judge == 'u') cout<<"JAPANESE"<<endl;
		else cout<<"KOREAN"<<endl;
	}
	return 0;
} 
