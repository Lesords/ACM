#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int book[32769];
int main(){
	int t;
	cin>>t;
	while(t--) {
		int n,cnt;
		cin>>n;
		cnt=0;
		memset(book,0,sizeof(book));
		for(int i=2;i<=n;i++) {
			if(n%i==0) {
				for(int j=i;j+i<=n;j+=i) {
					book[j]=1;
				}
			}
		}
		for(int i=1;i<n;i++) {
			if(!book[i]) cnt++;
		}
		cout<<cnt<<endl;
	}
	return 0;
} 
