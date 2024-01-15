#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	int t;
	cin>>t;
	string a;
	while(t--) {
		cin>>a;
		int ans = 0,tmp = 0;
		for(int i = 0;i < a.size();i++) {
			if(a[i] == 'O') {
				tmp++;
				ans += tmp;
			}
			else tmp = 0;
		}
		cout<<ans<<endl;
	}
	return 0;
}
