#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺����DP
//�� [������,������] Ϊ״̬
//dp[i][j]Ϊ����[i,j]Ϳɫ����Ҫ����С����
//�߽�״̬���ȳ�ʼ������λ��Ϊ�����Ȼ��i==jʱ����Ҫ�Ĵ���Ϊ1
//״̬ת�ƣ�
//��������[l,r]���ԣ����s[l]==s[r]���������Ϳl����r��ʱ�򣬶�Ϳһ��λ��
//�� dp[l][r] = min(dp[l-1][r], dp[l][r-1]) ����
//������ȣ�����Ա������������е㣬Ȼ������ֳ��������֣�ȡ��Сֵ
//Ŀ��״̬��dp[1][n]

const int MAXN = 55;
int dp[MAXN][MAXN];
char s[MAXN];
int main() {
    memset(dp,0x3f,sizeof(dp));             //��ʼ��ΪINF
    cin>>s+1;
    int n = strlen(s+1);
    for(int i = 1;i <= n;i++) dp[i][i] = 1; //�߽�Ϊ1
    for(int len = 1;len < n;len++) {        //�ȳ���
        for(int i = 1;i+len <= n;i++) {     //�����
            int j = i+len;                  //�յ�ֱ����
            //�����߽���ȣ�ֱ��ȡ��Сֵ
            if(s[i]==s[j]) dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
            else {
                //����ȡ�м�㣬�ָ�������֣�Ȼ��ȡ��Сֵ
                for(int k = i;k < j;k++) {  //��߿ɰ������ұ߲����ԣ�k+1
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]);
                }
            }
        }
    }
    cout<<dp[1][n];
    return 0;
}
