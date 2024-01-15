#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	string a,b;
	cin>>a>>b;
	long long ans_a = 0, ans_b = 0;
	for(int i = 0;i < a.size();i++) {
		ans_a += a[i] - '0';
	}
	for(int i = 0;i < b.size();i++) {
		ans_b += b[i] - '0';
	}
	cout<<ans_a*ans_b<<endl;//两个位数和的乘积
	return 0;
}
