#include<iostream>//ac
using namespace std;
int main() {
	int t,tmp;
	ios::sync_with_stdio(false);
	cin>>t;
	while(t--) {
		cin>>tmp;
		//��Ǻ��Ƿ�Ϊ360 
		if(!(360%(180-tmp))) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
} 
