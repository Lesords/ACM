#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e3+5;
ll dp[MAXN][MAXN],a[MAXN],b[MAXN];

//dp[i][j]:i����j�ֵ�ʱ��

int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i <= n;i++) cin>>b[i],b[i]+=b[i-1];
        memset(dp,0x3f,sizeof(dp));
        dp[0][0] = 0;
        for(int i = 1;i <= n;i++) {
        	dp[i][0] = 0;
        	for(int j = 1;j <= i;j++) {
        		dp[i][j] = min(dp[i][j],dp[i-1][j]);
        		if(dp[i-1][j-1]+a[i]<=b[i]) //ʱ�����С��b[i]
					dp[i][j] = min(dp[i][j],dp[i-1][j-1]+a[i]);
        	}
        }
        ll ans = INF;
        for(int i = n;i >= 1;i--) {//�Ӵ�С����
        	if(dp[n][i]<=b[n]) {//ֻҪʱ��С��b[n]��Ϊ��
        		ans = i;break;
        	}
        }
        cout<<ans<<endl;
    }
    return 0;
}
