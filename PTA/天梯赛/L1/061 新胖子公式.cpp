#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
    double a,b;
    cin>>a>>b;
    double ans = a/(b*b);//��ߵ�ƽ��������
    printf("%.1f\n",ans);
    if(ans>25) cout<<"PANG";
    else cout<<"Hai Xing";
    return 0;
}
