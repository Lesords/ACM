#include<iostream>//ac
#include<cstdio>
#include<cmath>
using namespace std;
const double PI = asin(1)*2;
int main() {
	int t;
	double x1,y1,x2,y2;
	cin>>t;
	while(t--) {
		cin>>x1>>y1>>x2>>y2;
		//����������ߵĳ��ȣ�Ȼ���������ҹ�ʽ��н�
		//cos c = (a*a + b*b - c*c)/(2*a*b)
		//�����Ϊ��ֵ��Ҫת��Ϊ����
		//���� = ��ֵ * 180 / PI
		double k_3 = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		double k_1 = sqrt(x1*x1+y1*y1);
		double k_2 = sqrt(x2*x2+y2*y2);
		double ans = acos((k_1*k_1+k_2*k_2-k_3*k_3)/(2.0*k_1*k_2));
		printf("%.2f\n",ans * 180 / PI);
	}
	return 0;
}
