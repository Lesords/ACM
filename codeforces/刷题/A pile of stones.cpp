#include<iostream>
#include<cstring>
using namespace std;
int main(){
	int n,max=0;
	char a[105]; 
	cin>>n>>a;
	for(int i=0;i<strlen(a);i++) {
		if(a[i]=='-'&&max!=0) max--;
		else if(a[i]=='+') max++;
	}
	cout<<max<<endl;
	return 0;
}
