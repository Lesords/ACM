#include<iostream>
#include<cstring>
#include<map>
using namespace std;
char a[1005],b[1005],c[1005];
int main() {
	map<char,char> map;
	cin>>a>>b;
	for(int i=0;i<strlen(a);i++) {
		map[a[i]]=b[i];
		map[a[i]-32]=b[i]-32;
	}
	cin>>c;
	int len=strlen(c);
	for(int i=0;i<len;i++) {
		if(c[i]>'9')c[i]=map[c[i]];//Êý×Ö²»×ª»» 
		cout<<c[i];
	}
	//cout<<c<<endl;
	return 0;
}
