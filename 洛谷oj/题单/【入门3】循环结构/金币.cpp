#include<iostream>//ac
using namespace std;
int main() {
	int n,ans = 0,money = 1,tmp = 0;
	cin>>n;//初始天数和总和都为0，钱为1
	while(n--) {
		++tmp;//天数++
		ans += money;//天数和钱一致时，钱++，天数清零
		if(tmp==money) money++,tmp = 0;
	}
	cout<<ans<<endl;
	return 0;
}
