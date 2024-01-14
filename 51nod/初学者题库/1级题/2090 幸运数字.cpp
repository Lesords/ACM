#include<iostream>//ac
using namespace std;
int main() {
	int n,flag = 0;
	cin>>n;
	while(n) {
		if(n%10==7) {
			flag = 1;
			cout<<"Yes"<<endl;
			break;
		}
		n /= 10;
	}
	if(!flag) cout<<"No"<<endl;
	return 0;
}
