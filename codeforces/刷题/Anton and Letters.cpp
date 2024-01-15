#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int book[27],ans=0;
int main() {
	char ch;
	while(1) {
		cin>>ch;
		if(ch=='{'||ch==','||ch==' ') continue;
		if(ch=='}') break;
		book[ch-'a']=1;
	}
	for(int i=0;i<26;i++)
		if(book[i]) ans++;
	cout<<ans<<endl;
	return 0;
}
