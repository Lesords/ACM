#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺���е�������ͬ�����ڲ����˵������ֵĽ����Ϊ0
//���Կ�������ԭ����Ĳ�֣���ÿ��������һ��������Ӧ
//ʣ��ļ�Ϊͬ�����֣�����ǰ׺���׺������
//���Բ�����Ϊ max(������ֺͣ�������ֺ�)
//�����Ϊ abs(������ֺ�-������ֺ�)+1

//���ӣ�3 2 2 2 6
// 3 3 3 3 6
//���Ľ������Ϊ 3 4 5 6�������� = ��4-1��+1


const int MAXN = 1e5+5;
ll a[MAXN],d[MAXN];//dΪ�������
int main() {
    ll n,up = 0,down = 0;//up���������ͣ�down���㸺����
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        if(i==1) d[i] = a[i];//��һ����Ϊ���鱾��
        else {
            d[i] = a[i]-a[i-1];//������
            if(d[i]>0) up += d[i];//������ֱ�Ӽ�
            else down -= d[i];//�����Ļ���Ҫ������������
        }
    }
    cout<<max(up,down)<<"\n"<<llabs(up-down)+1;
    return 0;
}
