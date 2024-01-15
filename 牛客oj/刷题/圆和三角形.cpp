#include<iostream>//ac
#include<cstdio>
using namespace std;

//题解：公式证明前部分为 1，而sin的最大值为1
//所以结果为 r + 1 
int main() {
	double r;
	scanf("%lf",&r); 
	printf("%.2f\n",r+1.0);
	return 0;
} 
