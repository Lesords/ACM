#include<iostream>//ac
#include<cstdio>
#include<cmath>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        char op;
        double a,ans = 0;
        cin>>op>>a;
        if(op=='M') ans = a/1.09;//��Ů�����
        else ans = a*1.09;//���������
        printf("%.2f\n",ans);//�Զ��������룬���账��
    }
    return 0;
}
