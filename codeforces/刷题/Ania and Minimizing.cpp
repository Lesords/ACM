#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[200005];
int main() {
	int n,k;
	cin>>n>>k>>a;
	for(int i=0;i<n&&k;i++) {
		if(i==0&&a[i]=='1'&&n!=1) continue;//首位为一且总位数不为一
		if(a[i]=='0') continue;//其他位为0 
		if(!i) {//第一位
			if(n!=1)a[i]='1';//不止有一位数
			else a[i]='0';
			k--;//操作次数
		}
		else {//其他位
			a[i]='0';
			k--;//操作次数
		}
	}
	cout<<a<<endl;
	return 0;
}
