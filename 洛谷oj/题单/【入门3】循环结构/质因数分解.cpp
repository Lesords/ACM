#include<iostream>//ac
using namespace std;
bool judge(int n) {//判断是否是质数
	for(int i = 2;i*i <= n;i++) {
		if(n%i==0) return 0;//有因子不是质数
	}
	return 1;//是质数
}
int main() {
	int n;
	cin>>n;
	for(int i = 2;i*i <= n;i++) {
		if(n%i==0&&judge(i)&&judge(n/i)) {//i是因子
			cout<<n/i<<endl;//输出较大值
			return 0;
		}
	}
	return 0;
}
