#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
	double tmp,ans;
	for(int i = 1;i <= 12;i++) cin>>tmp,ans += tmp;
	printf("$%.2f\n",ans/12);
	return 0;
} 
