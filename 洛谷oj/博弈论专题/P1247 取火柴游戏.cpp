#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺NIM���ģ������������������Ϊ0λ�ذ�̬
//��ô���ڱ�ʤ̬�Ĳ����ǽ���������ֵ��Ϊ ���ֵ^��ǰֵ
//ʹ���������ֵΪ��ԭ�������ֵ ^ �޸ĺ�����ֵ = 0
//����5^3 = 6
//�޸�Ϊ 5^6 ^ 3 = 0��Ҳ���ǽ�ԭ����5��Ϊ5^6����3

const int MAXN = 5e5+5;
int a[MAXN],ans;//ans��¼���������
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        ans ^= a[i];//�����������ֵ
    }
    if(ans==0) {//���ֵΪ0�����Ǳذ�̬
        cout<<"lose\n";
        return 0;
    }
    for(int i = 1;i <= n;i++) {//�ж���������ѡ��һ������ֵ��С�ڵ�ǰ���ļ���
        if((ans^a[i])<a[i]) {//ע�����ţ�����
            //ԭ����Ϊa[i]����Ҫ��Ϊans^a[i]����ֵ��Ϊ���ߵ�ֵ
            cout<<a[i]-(ans^a[i])<<" "<<i<<"\n";
            for(int j = 1;j <= n;j++) {
                if(j!=i) cout<<a[j]<<" ";
                else cout<<(ans^a[j])<<" ";//Ϊ��ǰ�������޸�Ϊ�������ֵ
            }
            break;//ֱ�ӽ���
        }
    }
    return 0;
}
