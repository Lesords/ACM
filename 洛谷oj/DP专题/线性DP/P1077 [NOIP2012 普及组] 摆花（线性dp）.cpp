#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺����dp
//���� ��ǰλ�õĻ����Ѿ�ѡ������� Ϊ״̬
//f[i][j]:�ڵ�ǰλ��i����i�ֻ����������Ѿ�ѡ����j�軨�ķ�����
//����ÿ��λ���� a[i] ��ѡ��
//ת�Ʒ���Ϊ f[i][j] += f[i-1][j-k] ������ǰѡ����k��iλ�õĻ�
//ע�⣺�ǵ��ж���ѡ�������Ƿ���ڵ��ڵ�ǰѡ�������

const int MAXN = 105;
const int MOD = 1000007;
int a[MAXN],f[MAXN][MAXN];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    f[0][0] = 1;//�߽�״̬
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= m;j++) {
            for(int k = 0;k <= a[i];k++) {//��ǰѡ������
                if(j>=k) {
                    f[i][j] = (f[i][j]+f[i-1][j-k])%MOD;
                }
            }
        }
    }
    cout<<f[n][m];
    return 0;
}
