#include<iostream>//ac
#include<cstring>
#include<cstdio>
using namespace std;
char a[1005];
int main() {
	int t;
	cin>>t;
	getchar();//��β�س��ַ�
	while(t--) {
		cin>>a;
		char tmp = a[0];
		int cnt = 1;
		for(int i = 1;i < strlen(a);i++) {
			if(a[i] == tmp) cnt++;
			else {
				if(cnt>1) cout<<cnt;//С��1�����
				cout<<tmp;
				tmp = a[i];//����
				cnt = 1;//����
			}
			if(i == strlen(a) - 1) {//��β����
				if(cnt>1) cout<<cnt;//С��1�����
				cout<<tmp;
			}
		}
		cout<<endl;
	}
	return 0;
}
