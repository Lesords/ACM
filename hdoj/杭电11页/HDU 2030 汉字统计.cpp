#include<iostream>//ac 
#include<cstring>
#include<cstdio>
using namespace std;
char a[505];
int main() {
	int T;
	cin>>T;
	getchar();//ĩβ�ַ�
	while(T--) {
		gets(a);
		int cnt = 0;
		for(int i=0;i<strlen(a);i++) {
			if(a[i]<0) {//����Ϊ����
				cnt++;
			}
		}
		cout<<cnt/2<<endl;
	}
	return 0;
}
