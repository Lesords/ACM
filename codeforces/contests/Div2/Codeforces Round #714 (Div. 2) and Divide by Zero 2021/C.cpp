#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺��dp[i]��ʾ������10����i�β������õĽ��
//��ôi�� [0,8] ��Χ�ڵĽ��Ϊ 2
//i = 9 ʱ���Ϊ3
//�����Ľ��Ϊ dp[i-10]+dp[i-9]
//���� i = 10ʱ����Ӧ���� 10  Ϊ (1+(10)) (0+10)  ��Ϊ d[1]+d[0]
//���У� dp[i] = dp[i-10] + dp[i-9]
//����ÿ��λ�ö�Ӧ�����ֵĹ���ֵ���Ƕ�����
//��ô����Ԥ���� MAXN ��Χ�ڵĹ���ֵ
//Ȼ����λ���㼴��

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
ll dp[MAXN];
int main() {
    for(int i = 0;i <= 8;i++) dp[i] = 2;//0-8�Ĺ���ֵΪ2
    dp[9] = 3;//9�Ĺ���ֵΪ3����Ϊ (1+9)(0+9) = 109��Ϊ��λ
    for(int i = 10;i < MAXN;i++) dp[i] = (dp[i-10]+dp[i-9])%MOD;//�ǵ�ȡģ
    fast;//��Ҫ���٣�����
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        ll ans = 0;
        while(n) {//��λ����
            int tmp = n%10;
            //����ǰλ�ü��ϲ�����mС��10����ô����ֵֻ��һλ
            //����ȡ �۳�10 ��dpֵ����
            ans = (ans+(tmp+m>=10?dp[tmp+m-10]:1))%MOD;//ȡģ
            n /= 10;
        }
        cout<<ans%MOD<<"\n";
    }
	return 0;
}
