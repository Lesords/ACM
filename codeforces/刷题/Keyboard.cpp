#include<iostream>//ac
#include<cstring>
#include<cstdio> 
using namespace std;
char a[105];
char book[] = "qwertyuiopasdfghjkl;zxcvbnm,./";
int main() {
	char op;
	cin>>op;
	int mov = op=='R'?-1:1;
	cin>>a;
	for(int i = 0;i < strlen(a);i++) {
		for(int j = 0;j < strlen(book);j++) {
			if(book[j]==a[i]) {//��ָ���ַ�
				a[i] = book[j+mov];//����
				break;
			}
		}
	}
	cout<<a<<endl;
	return 0;
}
