#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺��������״̬������ת�Ʒ���
//ÿ�θ��ݵ�ǰ�ߵĳ������ж�����޸�

const int MOD = 1e9+7;
ll dp[105][2];//dp[i][0/1]��i��ʾȨֵ�ͣ�0��ʾû��һ����Ϊd��1Ϊ�б߳�Ϊd
int main() {
    int n,k,d;
    cin>>n>>k>>d;
    dp[0][0] = 1;//��ʼ��Ϊ1����Ϊ0������ȨҲ��С��d
    for(int i = 1;i <= n;i++) {
        dp[i][0] = dp[i][1] = 0;//��ʼ��Ϊ0
        for(int j = 1;j <= min(i,k);j++) {//��Ȩ���ܳ�����ǰ�ܺ�i
            if(j>=d) {//��Ȩ���ڱ�׼d
                dp[i][1] = (dp[i][1]+dp[i-j][0])%MOD;//i-j������״̬���ɵ���
                dp[i][1] = (dp[i][1]+dp[i-j][1])%MOD;
            }
            else {//����ֻ��ȡ��Ӧ״̬
                dp[i][1] = (dp[i][1]+dp[i-j][1])%MOD;
                dp[i][0] = (dp[i][0]+dp[i-j][0])%MOD;
            }
        }
    }
    cout<<dp[n][1];
    return 0;
}
