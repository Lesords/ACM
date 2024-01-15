#include<iostream>//ac
using namespace std;
int main() {
	int n,m;
	cin>>n>>m;//n是起始值，m是目的值
	if(n>m) cout<<n-m<<endl;//起始值大,只能用减操作
	else {//逆向思维,乘变除,减变加（正向无法判断乘的时机）
		int cnt = 0;
		while(n<m) {
			m%2?m++:m/=2;
			cnt++;//m小于或等于n的操作
		} 
		cout<<cnt+n-m<<endl;//cnt再加上两值差
	}
	return 0;
}
