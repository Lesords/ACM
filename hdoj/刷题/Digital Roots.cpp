#include<iostream>
#include<cstring>
using namespace std;
char a[2000];
int main() {
	while(cin>>a) {
		if(a[0]=='0') break;
		int sum = 0;
		for(int i = 0;i< strlen(a);i++) {
			sum += a[i]-'0';
			if(sum >= 10) sum = 1 + sum%10;//只取数字和的个位数 
		}
		cout<<sum<<endl;
	}
	return 0;
} 
