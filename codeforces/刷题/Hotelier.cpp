#include<iostream>
#include<cstring>
using namespace std;
int a[10];
int left(){
	int i=0;
	while(a[i]) i++;
	return i;
}
int right() {
	int i=9;
	while(a[i]) i--;
	return i;
}
int main() {
	int t;
	char ch;
	cin>>t;
	for(int i=1;i<=t;i++) {
		cin>>ch;
		if(ch=='L') a[left()]=1;
		else if(ch=='R') a[right()]=1;
		else a[ch-'0']=0;
	}
	for(int i=0;i<10;i++) cout<<a[i];
	cout<<endl;
	return 0;
}
