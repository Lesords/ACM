#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int book[2050];
int main() {
	int T,n;
	cin>>T;
	while(T--) {
		cin>>n;
		memset(book,0,sizeof(book));
		long long tmp;
		for(int i=1;i<=n;i++) {
			cin>>tmp;
			if(tmp>2048) continue;
			book[tmp] ++;//标记 
		}
		if(book[2048]) {
			cout<<"YES"<<endl;
			continue;
		}
		for(int i=1;i<=1024;i+=i) {
			book[i+i] += book[i] / 2;//二合一 
		}
		book[2048]?cout<<"YES":cout<<"NO";
		cout<<endl;
	}
	return 0;
}
