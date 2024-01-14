#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
	double tmp,ans = 0;
	for(int i = 1;i <= 12;i++) {
		cin>>tmp;
		ans += tmp;
	}//求总和，然后除12即可
	printf("$%.2f",ans/12);
	return 0;
} 
