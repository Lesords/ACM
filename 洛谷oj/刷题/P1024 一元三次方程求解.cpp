#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
double a,b,c,d;//ʵ��������
double f(double x) {//���㺯��ֵ
    return a*x*x*x+b*x*x+c*x+d;
}
int main() {
    cin>>a>>b>>c>>d;
    int num = 0;
    for(double i = -100;i < 100;i+=0.001) {//����ö��
        //����Ϊ0.001��Ϊ����Ϊ��λ
        //��:1.220 1.221���ڸ��������Ϊ1.22
        if(f(i)*f(i+0.001)<0) {
            printf("%.2f ",i);
            num++;
            if(num==3) break;//ֻ���3��
        }
    }
    return 0;
}
