#include<iostream>//ac
#define ll long long
using namespace std;

//题解：从M对夫妇中选择N队，然后将这N队错排，即可使其N个都找错
//即 C(M,N) * 错排[n]

ll down[25],a[25];//down为n的阶乘，a为错排n个数的值
ll f(int a,int b) {//A(a,b)，a开始并且乘b次
	ll ans = 1;
	for(int i=a,j=1;j<=b;j++,i--) ans *= i;
	return ans;
}
int main() {
	int T,m,n;
	down[1] = 1;//第一个为1
	for(int i = 2;i<25;i++) down[i] = down[i-1] * i;//计算阶乘
	a[1] = 0;//只有一个，无法交换！！！
	a[2] = 1;//两个，可以互相交换，共一次
	for(int i = 3;i<25;i++) a[i] = (i-1) * (a[i-1]+a[i-2]);
	cin>>T;
	while(T--) {
		cin>>m>>n;//共m对夫妇，n个选错了
		cout<<f(m,n)/down[n]*a[n]<<endl;
		//组合数 * 错排数
	}
	return 0;
}
