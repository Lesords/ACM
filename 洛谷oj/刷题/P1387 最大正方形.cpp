#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 105;

//��⣺��̬�滮
//״̬����Ϊ��dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1
//dp[i][j]:��(i,j)Ϊ���½ǣ������γɵ���������εı߳�

int dp[MAXN][MAXN];
int main() {
    int n,m,ans = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            int tmp;
            cin>>tmp;
            if(tmp) {//���㵱ǰֵ�������´�
                dp[i][j] = min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
                ans = max(ans,dp[i][j]);
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
