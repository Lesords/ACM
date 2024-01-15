#include<iostream>//ac
using namespace std;
const int MAXN = 2e4 + 5;
int a[MAXN] = {1,1},num[3000];//只有两千多个
int main() {//0、1特殊处理
	int cnt = 0;
	for(int i = 2;i < MAXN;i++) {
		if(a[i]) continue;
		num[cnt++] = i;//储存每个素数
		for(int j = i+i;j < MAXN;j+=i) a[j] = 1;
	}
	int n,flag = 0;
	cin>>n;
	for(int i = 0;i < cnt&&!flag;i++) {//遍历所有素数
		if(num[i]>n) break;//素数大于n
		for(int j = 0;j < cnt&&!flag;j++) {//防止第三位出现 0
			if(num[j]+num[i]>=n) break;//两位数和不能大于 等于 n ！！！
			if(!a[n-num[i]-num[j]]) {//第三个数为素数
				cout<<num[i]<<' '<<num[j]<<' '<<n-num[i]-num[j]<<endl;
				flag = 1;
				break;//可以不加
			}
		}
	}
	return 0;
}
