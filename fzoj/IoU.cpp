#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int T;
	double x1,x2,y1,y2,w1,w2,h1,h2;
	cin>>T;
	while(T--) {
		double sum,uni,s_h,s_w;
		cin>>x1>>y1>>w1>>h1;
		cin>>x2>>y2>>w2>>h2;
		s_w = min(x1+w1,x2+w2) - max(x1,x2);
		//������� = ���ĩ�� - ��Զ��� 
		s_h = min(y1+h1,y2+h2) - max(y1,y2);
		//�����߶� = ���ĩ�� - ��Զ��� 
		sum = w1*h1 + w2*h2 - s_w*s_h;
		if(s_w>0&&s_h>0) printf("%.2f\n",s_w*s_h/sum);
		else printf("0.00\n");//�����ڵ������(������и���) 
	}
	return 0;
} 
