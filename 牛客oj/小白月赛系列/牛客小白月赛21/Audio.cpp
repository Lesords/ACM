#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
	double a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	//解方程推导公式
	double A = a*a-c*c+b*b-d*d;
	double B = 2*(a-c);
	double C = 2*(b-d);
	double D = a*a-e*e+b*b-f*f;
	double E = 2*(a-e);
	double F = 2*(b-f);
	double ans_x = (C*D-F*A)/(C*E-F*B);
	double ans_y = (A-B*ans_x)/C;
	printf("%.3f %.3f\n",ans_x,ans_y);
	return 0;
} 
