#include<iostream>//ac
#include<cstdio>
using namespace std;

//��ѧ������ʽ:���п���ֵ���ո��ʼ�Ȩ�ĺ�
//����������ֵ1*����1 + ����ֵ2*����2��*n

int main() {
	double n,x,a,b;
	cin>>n>>x>>a>>b;
	double ans = n*(a*x/100+b*(100-x)/100);
	printf("%.2f",ans);
	return 0;
}
