#include<iostream> 
#include<cstdio>
#include<cstring>
using namespace std;
char a[105];
int main() {
	while(gets(a)) {
		int flag = 1;//��ʼ�� 
		for(int i=0;i<strlen(a);i++) {
			if(a[i]==' ') {flag = 1;continue;}//�ո� 
			if(flag) a[i] -= 32,flag = 0;//����ĸ
		}
		puts(a);
	}
	return 0;
}
