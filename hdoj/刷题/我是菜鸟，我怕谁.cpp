#include<iostream>//ac
using namespace std;
int main() {
	int t,tmp;
	cin>>t;
	while(t--) {
		cin>>tmp;
		cout<<(tmp * tmp)%10000<<endl;//根据等差求和公式推导
		/*int ans = 0,cnt = 1;
		for(int i = 1;i <= tmp;i++) {
			ans += cnt%10000;
			cnt += 2;
		}
		cout<<ans%10000<<endl;*/
	}
	return 0;
}
