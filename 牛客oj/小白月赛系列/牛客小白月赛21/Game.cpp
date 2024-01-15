#include<iostream>//ac
using namespace std;
int main() {
	int n;
	cin>>n;
	int cnt = 0;
	if(n==1) {//特判
		cout<<"Nancy"<<endl;return 0;
	}//Nancy先手 
	//计算n可以分解为多少个质因数
	for(int i = 2;i <= n;i++) {//n在变化
		while(n%i==0) {//将n完全分解后，不会出现非质数的因数
			n /= i;//每次都需要更新n的值
			cnt++;//质因数数量++
		}
	}//偶数个质因数 可以操作奇数次
	if(cnt%2) cout<<"Nancy"<<endl;
	else cout<<"Johnson"<<endl;//偶数个质因数
	return 0;
}
