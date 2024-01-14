#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int a,b,n,flag = 0,drink_a = 0,drink_b = 0;//flag判断是否有人赢了
    cin>>a>>b>>n;
    for(int i = 1;i <= n;i++) {
        int talk1,talk2,num1,num2;
        cin>>talk1>>num1>>talk2>>num2;
        int aa = (num1==(talk1+talk2)?1:0);//判断是否有人需要喝酒
        int bb = (num2==(talk1+talk2)?1:0);
        if(aa==bb||flag) continue;//结果相同或者有结果时跳过
        drink_a += aa,drink_b += bb;//增加喝酒的数量
        if(drink_a>a) flag = 1;//判断两个人谁喝醉了
        if(drink_b>b) flag = 2;
    }
    if(flag==1) cout<<"A\n"<<drink_b;//1代表A先醉，输出B喝的数量
    else if(flag==2) cout<<"B\n"<<drink_a;
    return 0;
}
