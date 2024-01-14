#include<iostream>
#include<cstring>
using namespace std;
char a[100];
int f(char a[]) {
	int len = strlen(a);
	int flag = 0,mid;
	if(len%2) mid = len>>1;//找中点 
	else mid = len>>1 - 1;
	for(int i=0,j=len-1;i<=mid;i++,j--) {//左右同时比较 
		if(a[i]!=a[j]) {flag = 1;break;}
	}
	if(flag) return false;
	return true;
}
int main() {
	int n;
	while(cin>>n) {
		for(int i=1;i<=n;i++) {
			cin>>a;
			if(f(a)) cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
	return 0;
}
