#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
    int a,b,sum = 0,cnt = 1;
    cin>>a>>b;
    for(int i = a;i <= b;i++) {//ÿ����5�ı�����һ���س�
        sum += i;
        printf("%5d",i);//ÿ������ռ��λ6
        if(i!=b&&cnt%5==0) cout<<'\n';//����س����������һλ��������
        cnt++;
    }//���һλ����س�����������·��ظ����
    cout<<"\nSum = "<<sum;
    return 0;
}
