#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺������������Ѷ���ѹ��һ�У�����dp�����������
//����������ȱ�����㣬Ȼ��ÿ����һ�����ݾͽ���һ��һάdp

const int MAXN = 125;
int a[MAXN][MAXN],tmp[MAXN],dp[MAXN];//tmp�洢ѹ�к��ֵ��dp���������������
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= n;j++) cin>>a[i][j];
    int ans = -INF;//�и���
    for(int i = 1;i <= n;i++) {//i��ʾѹ�е����
        memset(tmp,0,sizeof(tmp));
        for(int j = i;j <= n;j++) {//�����i��ʼѹ�е��յ�n
            for(int k = 1;k <= n;k++) {//ѹ�в�����ÿ��ֻ���һ�У�
                tmp[k] += a[j][k];
            }
            memset(dp,0,sizeof(dp));//����dpǰ���ʼ��
            for(int k = 1;k <= n;k++) {//��һά���������
                dp[k] = max(dp[k-1]+tmp[k],dp[k]);
                ans = max(ans,dp[k]);//���´�
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
