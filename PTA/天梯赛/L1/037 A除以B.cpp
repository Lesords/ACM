#include<iostream>//ac
#include<cstdio>
using namespace std;
int main() {
    int a,b;
    cin>>a>>b;
    cout<<a<<"/";
    if(b<0) cout<<"(";//������Ҫ����
    cout<<b;
    if(b<0) cout<<")";
    if(b==0) cout<<"=Error";//��ĸΪ0���򱨴�
    else printf("=%.2f",a*1.0/b);//������λС��
    return 0;
}
