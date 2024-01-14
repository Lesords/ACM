#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    cout<<a<<"/";
    if(b<0) cout<<"(";//负数需要括号
    cout<<b;
    if(b<0) cout<<")";
    if(b==0) cout<<"=Error";//分母为0，则报错
    else printf("=%.2f",a*1.0/b);//保留两位小数
    return 0;
}
