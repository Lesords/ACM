#include<iostream>//ac
#define ll long long
using namespace std;
ll solve(ll n) {//�������λ���ܺ�
	ll ans = 0;
	while(n) {
		ans += n%10;
		n /= 10;
	}
	return ans;
}
int main() {
	ll n;
	cin>>n;
	while(n>=10) {//ֻҪ��Ϊ��λ��һֱִ��
		n = solve(n);
	}
	cout<<n;
	return 0;
}
