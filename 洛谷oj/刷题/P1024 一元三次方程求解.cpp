#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
double a,b,c,d;//实数！！！
double f(double x) {//计算函数值
    return a*x*x*x+b*x*x+c*x+d;
}
int main() {
    cin>>a>>b>>c>>d;
    int num = 0;
    for(double i = -100;i < 100;i+=0.001) {//暴力枚举
        //区间为0.001因为精度为两位
        //例:1.220 1.221存在根，结果则为1.22
        if(f(i)*f(i+0.001)<0) {
            printf("%.2f ",i);
            num++;
            if(num==3) break;//只输出3个
        }
    }
    return 0;
}
