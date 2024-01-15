#include<iostream>//ac  大数阶乘和加法
#include<cstring>
using namespace std;
const int MAXN = 105;
int a[MAXN],sum[MAXN],pos;
void multi(int n) {
	int rest = 0;//保留进位
	for(int i = 1;i < MAXN;i++) {
		a[i] = a[i]*n+rest;
		rest = a[i]/10;//进位为 /10
		a[i] %= 10;//当前位 %10
	}
}
void add() {
	for(int i = 1;i < MAXN;i++) {
		sum[i] += a[i];
		sum[i+1] += sum[i]/10; //下一位添加进位值
		sum[i] %= 10;//当前位 %10
	}
}
int main() {
	int n;
	cin>>n;
	if(!n) {//特判0
		cout<<'1'<<endl;return 0;
	}
	a[1] = 1;//乘法需初始化为1
	for(int i = 1;i <= n;i++) {
		multi(i);//乘
		add();//累加
	}
	for(int i = MAXN-1;i >= 1;i--) if(sum[i]) {//找到起始点
		pos = i;break;
	}//遍历输出即可
	for(int i = pos;i >= 1;i--) cout<<sum[i];
	cout<<endl;
	return 0;
}
