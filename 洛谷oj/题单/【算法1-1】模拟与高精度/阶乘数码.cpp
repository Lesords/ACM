#include<iostream>//ac
#include<cstring>
using namespace std;
const int MAXN = 3e3 + 5;
int a[MAXN];
void multi(int n) {//大数乘法，n为乘数
	int rest = 0;//保存进位，也可开第三方数组ans
	for(int i = 1;i < MAXN;i++) {
		a[i] = a[i]*n+rest;//进位另外加的
		rest = a[i]/10;//合在一起的话会重复乘！！！
		a[i] %= 10;
	}
}
int main() {
	int t,x,pos;
	cin>>t;
	while(t--) {
		int num = 0,s;
		memset(a,0,sizeof(a));//需要将a初始化
		a[1] = 1;//低位为1
		cin>>s>>x;
		for(int i = 1;i <= s;i++) multi(i);//求阶乘s！
		for(int i = MAXN - 1;i >= 1;i--) if(a[i]) {//找到pos
			pos = i;break;
		}//统计x的数量
		for(int i = pos;i >= 1;i--) if(a[i]==x) num++;
		cout<<num<<endl;
	}
	return 0;
}
