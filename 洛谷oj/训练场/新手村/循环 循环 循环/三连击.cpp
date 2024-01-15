#include<iostream>//ac
#include<cstring>
using namespace std;
int a[11];
int judge(int n) {
	while(n) {
		if(a[n%10]||n%10==0) return 0;//数字已存在或出现0！！！
		a[n%10] = 1;//标记出现过的数字
		n /= 10;
	}
	return 1;
}
int main() {
	for(int i = 123;i*3 <= 987;i++) {//起点和终点不出现重复数字
		memset(a,0,sizeof(a));//初始化标记数组
		if(judge(i)&&judge(i*2)&&judge(i*3)) {
			cout<<i<<' '<<i*2<<' '<<i*3<<endl;
		}
	}
	return 0;
}
