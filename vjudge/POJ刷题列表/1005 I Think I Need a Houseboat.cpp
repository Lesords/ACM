#include<iostream>//ac
#include<cmath>
#define PI acos(-1.0)
using namespace std;
int main() {
	int n;
	cin>>n;
	double x,y;
	for(int i = 1;i <= n;i++) {
		cin>>x>>y;
		double dis = sqrt(x*x+y*y);
		double year = 0,length = 0;
		while(length<dis) {
			year++;//年份++
			//根据 1/2*PI*(R^2-r^2) = 50 推出R的公式如下
			length = sqrt(100.0/PI + length*length);
		}
		cout<<"Property "<<i;
		cout<<": This property will begin eroding in year ";
		cout<<year<<"."<<endl;
	}
	cout<<"END OF OUTPUT."<<endl;
	return 0;
} 
