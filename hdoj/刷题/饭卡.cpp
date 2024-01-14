#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：小于5时直接输出即可
//大于5时，需要用5买最贵的东西（才能最小）
//剩余的钱也需要花掉最多
//也就是大于5时，分成两个部分计算

const int MAXN = 1005;
int a[MAXN], dp[MAXN];
//dp[i] 表示i余额可以买的最多东西
int main() {
	int t,rest;
	while(cin>>t&&t) {
		for(int i = 1;i <= t;i++) cin>>a[i];
		sort(a+1,a+t+1);//排序
		memset(dp,0,sizeof(dp));
		int maxx = a[t];//最贵的菜
		cin>>rest;
		if(rest<5) {//特判小于5！！！
			cout<<rest<<endl;continue;
		}
		rest -= 5;
		for(int i = 1;i < t;i++) {//不需要遍历最贵的
			//遍历容器的各种状态
			//每个大小的状态都有买和不买两个选择
			for(int j = rest;j >= a[i];j--) {
				dp[j] = max(dp[j],dp[j-a[i]]+a[i]);
				//要么不买，要么买，取较大值
			}//从容器大小 遍历 到截止大小（当前菜价）
		}
		//剩余的钱（扣除5的部分）-花掉最多+5-最贵的菜
		cout<<rest-dp[rest]+5-maxx<<endl;
	}
	return 0;
}
