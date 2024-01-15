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

//题解：用dp[i]表示对数字10进行i次操作所得的结果
//那么i在 [0,8] 范围内的结果为 2
//i = 9 时结果为3
//其他的结果为 dp[i-10]+dp[i-9]
//例： i = 10时，对应数字 10  为 (1+(10)) (0+10)  即为 d[1]+d[0]
//则有： dp[i] = dp[i-10] + dp[i-9]
//由于每个位置对应的数字的贡献值都是独立的
//那么可以预处理 MAXN 范围内的贡献值
//然后逐位计算即可

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
ll dp[MAXN];
int main() {
    for(int i = 0;i <= 8;i++) dp[i] = 2;//0-8的贡献值为2
    dp[9] = 3;//9的共享值为3，因为 (1+9)(0+9) = 109，为三位
    for(int i = 10;i < MAXN;i++) dp[i] = (dp[i-10]+dp[i-9])%MOD;//记得取模
    fast;//需要加速！！！
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        ll ans = 0;
        while(n) {//逐位计算
            int tmp = n%10;
            //若当前位置加上操作数m小于10，那么贡献值只有一位
            //否则取 扣除10 的dp值即可
            ans = (ans+(tmp+m>=10?dp[tmp+m-10]:1))%MOD;//取模
            n /= 10;
        }
        cout<<ans%MOD<<"\n";
    }
	return 0;
}
