#include<iostream> 
#include<cstdio>
#include<cstring>
using namespace std;
char a[105];
int main() {
	while(gets(a)) {
		int flag = 1;//初始化 
		for(int i=0;i<strlen(a);i++) {
			if(a[i]==' ') {flag = 1;continue;}//空格 
			if(flag) a[i] -= 32,flag = 0;//首字母
		}
		puts(a);
	}
	return 0;
}
