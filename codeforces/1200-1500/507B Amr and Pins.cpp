#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<algorithm>
#define two(x) (x)*(x)
using namespace std;

//��⣺����֮�䣬ֱ����̣���������·����Ϊ�����ľ���
//����ÿ���ƶ���ľ���Ϊ2*r��ȡ��Ĳ�ͬ�ɵ����ƶ��ĳ��Ȳ�ͬ
//Բ��·���Ľ���λ��Ϊ��Ĺ̶��㣬Խ�������Խ��
//���Խ��Ϊ ceil(dis/(2*r))

int main() {
    double r,x,y,xx,yy;
    scanf("%lf%lf%lf%lf%lf", &r, &x, &y, &xx, &yy);
    double dis = sqrt(two(xx-x)+two(yy-y));//�������
    printf("%d\n", (int)ceil(dis/(2*r)));//��������ȡ����
    return 0;
}
