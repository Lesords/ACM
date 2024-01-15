#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����dp
//�� dp[i][j] Ϊǰi��ѡ��j�������ֵ
//�߽磺�Ƚ�����λ�ó�ʼ��Ϊ-1��Ȼ��dp[i][0] = 0 ,���� 0 <= i <= n
//״̬ת�ƣ�
//��� dp[i-1][j-1] ��Ϊ���������� dp[i-1][j-1]+a[i] >= 0
//���� dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+a[i])
//����Ϊ dp[i][j] = dp[i-1][j]
//Ŀ�Ľ��������ǰ���º� dp[i][j] ��Ϊ�������� ans = max(ans, j)

const int MAXN = 2e3+5;
ll dp[MAXN][MAXN];
int a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    memset(dp, -1, sizeof(dp));//��ʼ������λ��Ϊ-1
    int ans = 0;
    for(int i = 0;i <= n;i++) dp[i][0] = 0;//�߽�Ϊ0��ʲô����ѡ��ֵΪ0
    for(int i = 1;i <= n;i++) {//iΪ��ǰλ�ã�����
        for(int j = 1;j <= i;j++) {//��ǰѡ�ĸ���
            //ǰһ��ֵ����С��0���ҵ�ǰ��Ҳ��С��0���������ǲ�С��0������
            if(dp[i-1][j-1]>=0&&dp[i-1][j-1]+a[i]>=0) {
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]+a[i]);//i�ǵ�ǰλ�ã�����
            }
            else dp[i][j] = dp[i-1][j];
            if(dp[i][j]>=0) ans = max(ans, j);//�������0��������j����ans��ֵ
        }
    }
    cout<<ans;
    return 0;
}
