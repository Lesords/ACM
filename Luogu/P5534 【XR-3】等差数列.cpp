#include<iostream>//ac
#define ll long long
using namespace std;
int main() {
	ll a,b,n,d;//数据爆int了！！！
	cin>>a>>b>>n;
	d = b-a;//求公差
	cout<<(n*a+(n*(n-1)*d/2));//求和公式
	return 0;
}
