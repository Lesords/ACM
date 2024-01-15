#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺����dp
//���������Լ�����Ա����λ��������״̬
//���������i��Ҫ���ʱ�򣬿϶���һ��Ա������Ҫ���λ��
//����ֻ��Ҫ��¼��������Ա����λ�ü��ɣ�����Сһά
//��ô����ʼ������Ϊ���ֵ
//���ڱ߽�λ����Ϊ f[0][1][2] = 0����ʾ��ǰ0����������������Ա������1��2λ��
//��ô���ڵ�����Ա����˵�����Խ���洢��Ҫ��a[0]�У���a[0] = 3
//��ô����ÿ�εļ�������У���������ת�ƵĿ�����
//��������Ա���ֱ��Ƶ�a[i]����ǰҪ���λ�ã���ȥ
//ע�⣺��Ҫ�ж�Ա����λ���Ƿ���ͬ
//Ŀ�Ľ��������m��Ҫ��ʱ��Ա����������λ�ã�ȡ��Сֵ

const int MAXN = 205;
const int MAXM = 1e3+5;
int c[MAXN][MAXN],a[MAXM];//c����洢�ƶ����ѣ�aΪҪ������
int dp[MAXM][MAXN][MAXN];//dp[i][j][k]��Ϊ����i��Ҫ��ʱ����������Ա������j��k��λ��
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) cin>>c[i][j];
    }
    for(int i = 1;i <= m;i++) cin>>a[i];
    memset(dp,0x3f,sizeof(dp));                         //��ʼ��Ϊ�����
    a[0] = 3;                                           //��¼Ա��λ�ã���ʼ��
    dp[0][1][2] = 0;                                    //��ǰ����Ϊ0
    int ans = INF;
    for(int i = 1;i <= m;i++) {                         //Ҫ��
        for(int j = 1;j <= n;j++) {
            for(int k = 1;k <= n;k++) {
                //����INF˵��״̬������
                if(dp[i-1][j][k]!=INF) {                //����һ��״̬������
                    //��Ҫ����Ա��λ��
                    if(j!=a[i]&&k!=a[i]) {              //Ա�� a[i-1] �Ƶ� a[i]
                        dp[i][j][k] = min(dp[i][j][k], dp[i-1][j][k]+c[a[i-1]][a[i]]);
                    }
                    if(j!=a[i]&&a[i-1]!=a[i]) {         //Ա�� k �Ƶ� a[i]
                        dp[i][j][a[i-1]] = min(dp[i][j][a[i-1]], dp[i-1][j][k]+c[k][a[i]]);
                    }
                    if(k!=a[i]&&a[i-1]!=a[i]) {         //Ա�� j �Ƶ� a[i]
                        dp[i][a[i-1]][k] = min(dp[i][a[i-1]][k], dp[i-1][j][k]+c[j][a[i]]);
                    }
                }
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            ans = min(ans, dp[m][i][j]);                //��m����n��mΪ�������������
        }
    }
    cout<<ans<<"\n";
    return 0;
}
