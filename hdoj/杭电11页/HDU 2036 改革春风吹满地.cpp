#include<iostream>//ac
#include<cstdio> 
#include<cmath>
using namespace std;
struct tri{
	int x,y;
}a[105];
double multi_cross(tri n,tri m) {//��������
	//|a X b| = ax * by - ay * bx
	//ע�⣺�ұ�Ϊi��j�������������
	return (n.x-a[1].x)*(m.y-a[1].y) - (n.y-a[1].y)*(m.x-a[1].x);
}
int main() {
	int n;
	double kk;
	while(cin>>n&&n) {
		for(int i = 1;i <= n;i++) cin>>a[i].x>>a[i].y;
		double ans = 0;
		for(int i = 2;i < n;i++) {
			ans += multi_cross(a[i],a[i+1]);
			//����Ҫ����ֵ��fabs�������ȹ���
		}
		printf("%.1f\n",ans/2);//������Ϊ�����Σ���2��Ϊ������
	}
	return 0;
}
