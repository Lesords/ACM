#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺ÿ��Ҫô������k��Ҫô������1������˵����������>=x��λ�ã�Ȼ��������
//��ôǰ�������ľ��뼴Ϊ step*(1+step)/2  ���Ȳ�͹�ʽ��
//��ô���ڲ�x��λ�ÿ϶�С��step����������ߣ������Կ�����һ������k������1
//��ô������С�Ľ���Ϊ +1 -> -1������Ϊ2�����Ե��������1ʱ������Ҫ������һ��

int main() {
    int t;
    cin>>t;
    while(t--) {
        int x,step = 1;
        cin>>x;
        while((1+step)*step<x*2) step++;//������������
        if((1+step)*step/2==x+1) step++;//���Ϊ1��ʱ����Ҫ������һ��
        cout<<step<<"\n";
    }
    return 0;
}
