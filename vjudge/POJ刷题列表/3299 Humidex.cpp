#include<iostream>//ac
#include<cstdio>
#include<cmath>
using namespace std;
double f(double x) {//·µ»Ø 2.718281828^x ½üËÆÓÚ e^x
	return pow(2.718281828,x);
} 
int main() {
	char ch;
	double temp,dew,hum;
	while(1) {
		temp = dew = hum = 0; 
		for(int i = 1;i <= 2;i++) {
			cin>>ch;
			if(ch=='E') return 0;
			if(ch=='T') cin>>temp;
			else if(ch=='D') cin>>dew;
			else cin>>hum;
		}
		if(temp&&hum) {//temp&&hum
			double h = hum - temp;
			double e = (h/0.5555)+10.0;
			double x = ((1.0/273.16)-(log(e/6.11)/(log(2.718281828)*5417.753)));
			dew = 1.0/x - 273.16;
		}
		else {
			double e = 6.11*f(5417.7530*((1.0/273.16)-(1/(dew+273.16))));
			double h = 0.5555*(e-10.0);
			if(temp&&dew) hum = temp + h;
			else temp = hum - h;
		}
		printf("T %.1f D %.1f H %.1f\n",temp,dew,hum);
	}
	return 0;
}
