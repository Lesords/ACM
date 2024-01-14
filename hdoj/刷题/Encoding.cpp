#include<iostream>//ac
#include<cstring>
#include<cstdio>
using namespace std;
char a[1005];
int main() {
	int t;
	cin>>t;
	getchar();//结尾回车字符
	while(t--) {
		cin>>a;
		char tmp = a[0];
		int cnt = 1;
		for(int i = 1;i < strlen(a);i++) {
			if(a[i] == tmp) cnt++;
			else {
				if(cnt>1) cout<<cnt;//小于1则忽略
				cout<<tmp;
				tmp = a[i];//更新
				cnt = 1;//重置
			}
			if(i == strlen(a) - 1) {//结尾特判
				if(cnt>1) cout<<cnt;//小于1则忽略
				cout<<tmp;
			}
		}
		cout<<endl;
	}
	return 0;
}
