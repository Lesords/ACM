#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e3+5;
int a[MAXN][MAXN],dp[MAXN][MAXN];
int main() {
    int r;
    cin>>r;
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= i;j++) {
            cin>>a[i][j];
        }
    }
    for(int i = 1;i <= r;i++) dp[r][i] = a[r][i];//��ʼ�������һ��
    for(int i = r-1;i >= 1;i--) {//�������ϱ���
        for(int j = 1;j <= i;j++) {
            // ��ǰֵ + ���½ϴ�ֵ
            dp[i][j] = a[i][j] + max(dp[i+1][j],dp[i+1][j+1]);//�º�����
        }
    }
    cout<<dp[1][1];//���Ϊ��
    return 0;
}
