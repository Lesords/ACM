#include<iostream>//ac  直接递归会超时
using namespace std;
int book[1005];
int solve(int n) {//n代表原数
	int tmp = 0;
	if(book[n]) return book[n];//已计算，直接返回
	for(int i = 1;i <= n/2;i++) {
		tmp += solve(i);//每次递归的时候都会保存计算值
	}
	return book[n] = tmp + 1;//记忆化处理
}
int main() {
	int n;
	cin>>n;
	cout<<solve(n)<<endl;
	return 0;
}
