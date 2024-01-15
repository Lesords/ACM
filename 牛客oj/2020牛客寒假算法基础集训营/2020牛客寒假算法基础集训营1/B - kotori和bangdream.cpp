#include<iostream>//ac
#include<cstdio>
using namespace std;

//数学期望公式:所有可能值按照概率加权的和
//即：（可能值1*概率1 + 可能值2*概率2）*n

int main() {
	double n,x,a,b;
	cin>>n>>x>>a>>b;
	double ans = n*(a*x/100+b*(100-x)/100);
	printf("%.2f",ans);
	return 0;
}
