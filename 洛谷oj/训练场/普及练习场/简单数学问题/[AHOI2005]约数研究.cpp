#include<iostream>//ac
using namespace std;

//题解：由于 1-n的因子个数和 中各个数作为因子的数量一定
//则每次只需要统计各个因子出现的次数即可
//因子i次数：f(i) = n / i  (n为目标数)  ！！！
 
int main() {
	int n,ans = 0;
	cin>>n;
	//1-n中各个数出现的次数
	for(int i = 1;i <= n;i++) ans += n/i;
	cout<<ans<<endl;
	return 0;
}
