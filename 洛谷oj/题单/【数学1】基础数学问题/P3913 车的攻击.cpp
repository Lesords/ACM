#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺��¼�����г����к��У�ȥ��
//Ȼ�󱻹����ĸ���������Ϊ�����к����������ٿ۳��м��ظ��Ĳ���
//�м��ظ����ֵ����� = ���� * �������ɻ�ͼ���
//������������ = n*���� + n*���� - ����*����

const int MAXN = 1e6+5;
int r[MAXN],c[MAXN];//��¼��Ӧ�����к���
int main() {
    ios::sync_with_stdio(0);//����
    cin.tie(0),cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= k;i++) {
        cin>>r[i]>>c[i];
    }
    sort(r+1,r+k+1);//����ҿ�������
    sort(c+1,c+k+1);
    int posr = unique(r+1,r+k+1)-r-1;//����ҿ�������
    int posc = unique(c+1,c+k+1)-c-1;//��-1��uniqueΪȥ�غ����һ��λ��
    cout<<n*1ll*(posr+posc)-(posr*1ll*posc);
    return 0;
}
