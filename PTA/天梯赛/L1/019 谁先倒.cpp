#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int a,b,n,flag = 0,drink_a = 0,drink_b = 0;//flag�ж��Ƿ�����Ӯ��
    cin>>a>>b>>n;
    for(int i = 1;i <= n;i++) {
        int talk1,talk2,num1,num2;
        cin>>talk1>>num1>>talk2>>num2;
        int aa = (num1==(talk1+talk2)?1:0);//�ж��Ƿ�������Ҫ�Ⱦ�
        int bb = (num2==(talk1+talk2)?1:0);
        if(aa==bb||flag) continue;//�����ͬ�����н��ʱ����
        drink_a += aa,drink_b += bb;//���ӺȾƵ�����
        if(drink_a>a) flag = 1;//�ж�������˭������
        if(drink_b>b) flag = 2;
    }
    if(flag==1) cout<<"A\n"<<drink_b;//1����A�������B�ȵ�����
    else if(flag==2) cout<<"B\n"<<drink_a;
    return 0;
}
