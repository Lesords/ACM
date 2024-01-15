#include<iostream>//ac
using namespace std;
int solve(int n) {//统计2的个数
	int ans = 0;
	while(n) {
		if(n%10==2) ans++;
		n /= 10;
	}
	return ans;
}
int main() {
	int l,r,ans = 0;
	cin>>l>>r;
	for(int i = l;i <= r;i++) {
		ans += solve(i);
	}
	cout<<ans;
	return 0;
}
