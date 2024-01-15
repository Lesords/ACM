#include<iostream>
#define MAXN 202
using namespace std;
int a[MAXN],b[MAXN],book[MAXN],flag;
int main(){
	int n,m,ans_a,ans_b;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		book[a[i]]=1;
	}
	cin>>m;
	for(int i=1;i<=m;i++) {
		cin>>b[i];
		book[b[i]]=1;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			if(!flag)
				if(!book[a[i]+b[j]]) {// don't exist
					ans_a=a[i];
					ans_b=b[j];
					flag=1;
					break;
				}
		}
	}
	cout<<ans_a<<' '<<ans_b<<endl;
	return 0;
}
