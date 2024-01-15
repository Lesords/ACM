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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：线性dp
//令 dp[i][j] 为前i个剩余j个时，值与下标匹配的最多数量
//边界状态：所有情况都是0，因为dp存储的匹配数量，初始化全为0，没有1的情况！！!

//状态转移：遍历所有的数字，每个数字有两种选择：删和不删
//1. 若删，则有 dp[i][j] = max(dp[i][j], dp[i-1][j]);
//2. 若不删，则需要判断当前值是否为 j，因为剩余j个，所以当前值的坐标即为j
//若相等，则值需+1
//则有 dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i]==j);

//目的状态：由于需要使操作数最小，且匹配数需要大于等于k
//所以可以遍历 dp[n][i],其中 0 <= i <= n
//寻找里面的操作数最小的情况，由于i为剩余数量，则n-i为操作次数
//要使操作次数最小，则i需要较大，所以可以倒序遍历，找到的第一个即为结果

const int MAXN = 2e3+5;
const int MOD = 1e9+7;
int dp[MAXN][MAXN],a[MAXN];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        memset(dp, 0, sizeof(dp));//初始化都为0
        int n,k;
        cin>>n>>k;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= i;j++) {//j不能超过i的数量！！！
                //不删，需要判断当前值是否等于j
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+(a[i]==j));
                //删
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
        int ans = -1;//初始化为-1，表示无解
        for(int i = n;i >= 0;i--) {
            if(dp[n][i]>=k) {//倒序寻找，第一个即为答案
                ans = n-i;//i为剩余数量，n-i为操作次数
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
