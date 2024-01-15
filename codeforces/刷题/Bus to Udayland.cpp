#include<iostream>//ac
using namespace std;
char a[1005][8];
int main() {
	int t,flag = 0;
	cin>>t;
	for(int i = 1;i <= t;i++) {
		cin>>a[i];
		if(!flag&&a[i][0]==a[i][1]&&a[i][0]=='O') {
			flag = 1;
			a[i][0] = a[i][1] = '+';
		}
		if(!flag&&a[i][3]==a[i][4]&&a[i][3]=='O') {
			flag = 1;
			a[i][3] = a[i][4] = '+';
		}
	}
	if(!flag) {
		cout<<"NO"<<endl;
		return 0;
	}
	cout<<"YES"<<endl;
	for(int i = 1;i <= t;i++) {
		if(i!=1) cout<<endl;
		cout<<a[i];
	}
	return 0;
}
