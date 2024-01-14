#include<iostream>
#include<cstdio>
using namespace std;
int main() {
	double a,b,sum;
	char name[20];
	while(cin>>name>>a>>b) {
		sum += a*b;
	}
	printf("%.1f\n",sum);
	return 0;
} 
