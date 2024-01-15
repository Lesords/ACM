#include<iostream>
#include<cstring>
using namespace std;
int book[30];
int main() {
	int T,flag=0;
	char tmp;
	cin>>T;
	while(T--) {
		cin>>tmp;
		if(tmp>='a'&&tmp<='z') 
			book[tmp-'a']++;
		else 
			book[tmp-'A']++;
	}
	for(int i=0;i<=25;i++) {
		if(!book[i]) {
			flag=1;
			break;
		}
	}
	if(flag) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	return 0;
} 
