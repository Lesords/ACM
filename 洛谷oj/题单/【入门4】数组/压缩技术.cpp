#include<iostream>//ac
using namespace std;
const int MAXN = 40005;
int a[MAXN];
int main() {
	int n,tmp,cnt = 1,op = 0;
	cin>>n;
	while(cin>>tmp) {//不知道还有多少数据
		while(tmp) {//tmp个op数
			a[cnt++] = op,tmp--;//从cnt开始赋值
		}
		op ^= 1;//取反
	}
	for(int i = 1;i <= n*n;i++) {
		cout<<a[i];
		if(i%n==0) cout<<endl;//只需要在倍数位置输出回车
	}
	return 0;
}
