#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//���⣺�������ǻ����������䣬�������ֻ�������������
//i��������Ϊ��һ���컨��k���׻�
//�ɵ�״̬����Ϊ��dp[i] = dp[i-1]+dp[i-k]
//Ȼ����ǰ׺�ͼ�¼�������ѯ�����ʱ��ע�� +MOD

const ll MOD = 1e9+7;
const int MAXN = 1e5+5;
ll sum[MAXN],dp[MAXN];
int main() {
    int t,k;
    cin>>t>>k;
    dp[0] = 1;//��ʼ��Ϊ1
    for(int i = 1;i < MAXN;i++) {
        dp[i] = (dp[i]+dp[i-1])%MOD;//һ��컨
        if(i>=k) {
            dp[i] = (dp[i]+dp[i-k])%MOD;//k��׻�
        }
    }
    for(int i = 1;i < MAXN;i++) {//ǰ׺��
        sum[i] = (sum[i-1]+dp[i])%MOD;
    }
    while(t--) {
        int a,b;
        cin>>a>>b;//����ȡ�ͼǵ�+MOD����Ȼ����ָ���������
        cout<<(sum[b]-sum[a-1]+MOD)%MOD<<"\n";
    }
    return 0;
}
