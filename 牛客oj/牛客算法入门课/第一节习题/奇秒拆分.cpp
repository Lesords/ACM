#include<iostream>//ac
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		int ans = 0;//统计数量
		cin>>n;
		for(int i = 1;i <= n;i++) {
			if(n%i==0) {//可以被整除
				//不能出现重复的，所以只执行一次
				ans++;
				n /= i;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
