#include<iostream>//ac
#include<cstdio>
#include<cstring>
using namespace std;
char a[100];
int len;
int isperiod(int k) {
	int flag = 0;
	for(int i = 0;i < len;i += k) {//周期倍增加
		for(int j = i;j < i+k;j++) {
			if(j+k>=len) break;//溢出
			if(a[j]!=a[j+k]) flag = 1;//两个周期比较
		}
	}
	return !flag;//0表示周期匹配成功
}
int main() {
	int t,flag = 0;
	cin>>t;
	while(t--) {
		getchar();//处理多余空行
		int ans = 0;
		cin>>a;
		len = strlen(a);
		for(int i = 1;i <= len;i++) {
			if(isperiod(i)&&!(len%i)) {//大小可以被周期整除！
				ans = i;
				break;
			}
		}
		if(flag++) cout<<endl;
		cout<<ans<<endl;//末尾endl
	}
	return 0;
}
/*wa样例
3

aba

abca

abcda*/ 
