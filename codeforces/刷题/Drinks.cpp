#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	int T;
	double tmp,cnt=0,now;
	cin>>T;
	for(int i=1;i<=T;i++) {
		cin>>tmp;
		cnt+=tmp/100;
	}
	printf("%.12f\n",cnt/T*100);
	return 0;
} 
