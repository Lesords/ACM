#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺������ = �������� + ��������
//���Ա������й��ľ��μ���
//������������Ϊ: ���� - ���γ� + 1

int main() {
    int n,m;
    ll square = 0,rec = 0;//�����int
    cin>>n>>m;//n��m��
    for(int i = 1;i <= n;i++) {//�з���ľ��γ���
        for(int j = 1;j <= m;j++) {//�з���ľ��γ���
            if(i==j) square += (n-i+1)*1ll*(m-j+1);//������
            else rec += (n-i+1)*1ll*(m-j+1);//������
        }
    }
    cout<<square<<' '<<rec<<endl;
    return 0;
}
