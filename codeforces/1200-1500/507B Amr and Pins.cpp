#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<algorithm>
#define two(x) (x)*(x)
using namespace std;

//题解：两点之间，直线最短，所以最优路径长为两点间的距离
//由于每次移动最长的距离为2*r，取点的不同可导致移动的长度不同
//圆与路径的交点位置为最长的固定点，越往后距离越短
//所以结果为 ceil(dis/(2*r))

int main() {
    double r,x,y,xx,yy;
    scanf("%lf%lf%lf%lf%lf", &r, &x, &y, &xx, &yy);
    double dis = sqrt(two(xx-x)+two(yy-y));//计算距离
    printf("%d\n", (int)ceil(dis/(2*r)));//计算结果（取整）
    return 0;
}
