#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN];
int gcd(int a,int b) {//计算最大公约数
	return b?gcd(b,a%b):a;//更新写法（处理a或b为0的情况）
}
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+1+n);//排序
	int step = a[2]-a[1];//第一个公差
	for(int i = 3;i <= n;i++) {
		step = gcd(step,a[i]-a[i-1]);//取差值之间的最大公约数
	}
	if(step==0) {//为0表示全一致，已为等差数列
		cout<<n<<endl;
		return 0;
	}
	cout<<(a[n]-a[1])/step+1;//总差值/公差+1 为数列数量
	return 0;
}
