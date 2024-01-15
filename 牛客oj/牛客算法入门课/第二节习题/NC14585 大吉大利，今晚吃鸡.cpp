#include<iostream>//ac
using namespace std;
int solve(int n) {
	if(n==0) return 0;//特判0和1
	if(n==1) return 2;
	// n-1 个盘移到终点 + 大盘移到中间
	// + n-1 个盘移到起点 + 大盘移到终点
	// + n-1 个盘移到终点
	return 3*solve(n-1)+2;
}
int main() {
	int n,ans;
	while(cin>>n) {//多组输入
		cout<<solve(n)<<'\n';
	}
	return 0;
}
