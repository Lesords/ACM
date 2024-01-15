#include<iostream>
#include<cstring>
using namespace std;
char a[105],b[105],c[105];
int book[30],cnt[30],flag=0;
int main() {
	cin>>a>>b>>c;
	for(int i=0;i<strlen(a);i++) {
		book[a[i]-'A']++;
	}
	for(int i=0;i<strlen(b);i++) {
		book[b[i]-'A']++;
	}
	for(int i=0;i<strlen(c);i++) {
		cnt[c[i]-'A']++;
	}
	for(int i=0;i<=25;i++) {
		if(book[i]!=cnt[i]) {//ÅÐ¶Ï´óÐ¡ 
			flag=1;
			break;
		}
	}
	flag?cout<<"NO"<<endl:cout<<"YES"<<endl;
	return 0;
}
