#include<iostream>//ac
using namespace std;
int main() {
	int t,n,m;
	cin>>t;
	while(t--) {
		cin>>n;
		int ans = n,tmp;
		m = n;//n瓶 m盖
		while(n>=3||m>=4) {
			tmp = n/3 + m/4;//置换后得到饮料
			n %= 3, m %= 4;//剩余的
			ans += tmp, n += tmp, m += tmp;//更新盖子和瓶子数量
		}
		cout<<ans<<endl;
	}
	return 0;
}
