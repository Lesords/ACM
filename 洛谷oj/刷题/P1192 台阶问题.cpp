#include<iostream>//ac
using namespace std;
const int MAXN = 1e5+5;
const int MOD = 100003;
int a[MAXN] = {1,1};//处于底层和1阶的方法都只有一种
int main() {
	int n,k;
	cin>>n>>k;
	for(int i = 2;i <= n;i++) {
		int ans = 0;//ans为到达i层的方法数
		//首先起点必须大于0（底层或以上）
		//两个间距之差不能大于k
		for(int j = i-1;j >= 0&&i-j<=k;j--) {
			ans = (ans+a[j])%MOD;//求和并取模
		}
		a[i] = ans;//保存结果
	}
	cout<<a[n];
	return 0;
}
