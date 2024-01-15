#include<iostream>//ac
using namespace std;
int solve(int n) {//取相反数
	int ans = 0;
	while(n) {//会自动删除前置零
		ans = ans*10+n%10;
		n /= 10;
	}
	return ans;
}
int main() {
	int n;
	cin>>n;
	cout<<n+solve(n)<<endl;
	return 0;
}
