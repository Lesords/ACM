#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

//���⣺�Ӹ���������ѡ��һ���Ӽ�
//ʹ���Ӽ����ڵ���ʣ�༯�ϵ��ܺͣ������Ӽ�����ѡһ��ɾ����С�ڵ���ʣ�༯�ϵ��ܺ�
//��ô���ڼ��Ͻ��д�С��������ʹ��ÿ�β���ʱ����ǰֵ��Ϊ������Сֵ
//�� dp[i] ��ʾ�����ܺ�Ϊi�ķ�����
//��ô����ÿ��������˵������ѡ�Ͳ�ѡ������������������01����
//�߽�״̬��dp[0] = 1������Ϊ0 ������ѡ�����Ϊ1
//�����Ǽ���������ת�ƹ������ۼ�
//��������ʱ����Ҫ�ж��Ӽ������Ƿ�����

const int MAXN = 305;
const int MOD = 1e9+7;
ll a[MAXN],dp[MAXN*500];
bool cmp(ll a,ll b) {//�Ӵ�С����
    return a>b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        ll sum = 0,ans = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            sum += a[i];//�ۼӣ���ԭ�����ܺ�
        }
        sort(a+1,a+n+1,cmp);//�Ӵ�С����
        memset(dp, 0, sizeof(dp));//��ʼ��Ϊ0
        dp[0] = 1;//�߽�Ϊ1
        for(int i = 1;i <= n;i++) {
            for(int j = sum;j >= a[i];j--) {//����Ϊ01����
                dp[j] = (dp[j]+dp[j-a[i]])%MOD;//�ۼӣ���ѡ�Ͳ�ѡ���ǵ�ȡģ
                if(j>=sum-j&&j-a[i]<=sum-j) {//�Ӽ���������������
                    ans = (ans+dp[j-a[i]])%MOD;
                    //ֻ���ѡ����������Ϊ��Ҫ�жϵ�ǰ��ѡ�Ƿ�С�ڵ���ʣ�༯�ϣ�����
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
