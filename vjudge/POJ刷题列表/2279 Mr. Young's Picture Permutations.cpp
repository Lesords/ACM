#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺��άdp����ǰ������״̬

int a[6];
int main() {
    int n;
    while(cin>>n&&n) {
        for(int i = 1;i <= n;i++) cin>>a[i];
        while(n<5) {
            a[++n] = 0;
        }//ʣ�಻���Ĳ���
        ll dp[a[1]+1][a[2]+1][a[3]+1][a[4]+1][a[5]+1];//���Ĵ�С���1
        memset(dp,0,sizeof(dp));//���㣡����
        dp[0][0][0][0][0] = 1;//�߽�״̬������ѡΪ1
        //Ҫô�ڵ�һ��δ����ʱ��ѡ���һ��
        //Ҫô�жϵ�ǰ���Ƿ�������һ�е�����
        for(int i = 0;i <= a[1];i++) {
            for(int j = 0;j <= a[2];j++) {
                for(int k = 0;k <= a[3];k++) {
                    for(int u = 0;u <= a[4];u++) {
                        for(int p = 0;p <= a[5];p++) {
                            //��һ�У�ֱ���ж��Ƿ�δ���Ϳ��Ը���
                            if(i<a[1]) dp[i+1][j][k][u][p] += dp[i][j][k][u][p];
                            //�����У���Ҫ�ж��Ƿ�������һ�е�����������
                            if(j<a[2]&&i>j) dp[i][j+1][k][u][p] += dp[i][j][k][u][p];
                            if(k<a[3]&&j>k) dp[i][j][k+1][u][p] += dp[i][j][k][u][p];
                            if(u<a[4]&&k>u) dp[i][j][k][u+1][p] += dp[i][j][k][u][p];
                            if(p<a[5]&&u>p) dp[i][j][k][u][p+1] += dp[i][j][k][u][p];
                        }
                    }
                }
            }
        }
        cout<<dp[a[1]][a[2]][a[3]][a[4]][a[5]]<<"\n";
    }
    return 0;
}
