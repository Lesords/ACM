#include<iostream>//ac
#include<string>
using namespace std;
const int MAXN = 1e5 + 5;
char a[MAXN];
int main() {
	int t;
	string a;
	cin>>t;
	while(t--) {
		cin>>a;
		int ans = 0;
		for(int i = 0;i < a.size();i++) {
			ans += a[i] - 'A' + 1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
