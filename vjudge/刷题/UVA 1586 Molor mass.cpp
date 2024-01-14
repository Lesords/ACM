#include<iostream>//ac
#include<cstdio>
#include<cstring>
using namespace std;
char a[85];
int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>a;
		double tmp,ans = 0;
		for(int i=0;i<strlen(a);) {
			if(a[i]=='C') tmp = 12.01;
			else if(a[i]=='H') tmp = 1.008;
			else if(a[i]=='O') tmp = 16;
			else if(a[i]=='N') tmp = 14.01;
			if(i==strlen(a)-1||a[i+1]<'0'||a[i+1]>'9'){
				//只有一个原子
				ans += tmp;
				i++;//移一位
				continue;
			}
			if(a[i+2]<'0'||a[i+2]>'9') {//一位整数
				ans += tmp * (a[i+1]-'0');
				i += 2;//移两位
			}
			else {//两位整数
				ans += tmp *((a[i+1]-'0')*10+a[i+2]-'0');
				i += 3;//移三位
			} 
			
		}
		printf("%.3f\n",ans);
	}
	return 0;
} 
