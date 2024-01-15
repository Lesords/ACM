#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：计数dp，从前往后推状态，所以最终的状态在 (n+1)
//由于题目可知，需要匹配的字符只有两个
//所以当当前为 t0 字符时，需要判断 t0和t1 是否相等，若相等，则和前面的 t0 可匹配
//若当前字符为 t1 字符时，直接输出前面的 cnt个t0 即可
//利用上述两种情况来推状态方程即可
//需要将 除初始位置以外的状态赋值为 -1，表示无值
//对应动态规划过程中，只有三种情况：不修改当前字符，修改当前字符为t0，修改当前字符为t1

const int MAXN = 205;
char s[MAXN],t[4];
int dp[MAXN][MAXN][MAXN];//dp[i][j][k]表示前(i-1)个修改j个字符拥有k个t0的最大匹配数
int main() {
    memset(dp,-1,sizeof(dp));//初始化为-1，表示所有状态还没有值
    int n,k;
    cin>>n>>k>>s+1>>t;
    dp[1][0][0] = 0;//初始化起始状态为0，在第一个字符的位置0次操作0个t0的匹配数为0
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= k;j++) {//操作数从0开始，到k结束
            for(int cnt = 0;cnt <= n;cnt++) {//t0数量从0开始，到n结束
                //如果当前的位置为-1，表示当前状态没有出现过，则直接跳过
                if(dp[i][j][cnt]==-1) continue;
                int e0 = s[i] == t[0];//判断当前位置是否为t0
                int e1 = s[i] == t[1];//判断当前位置是否为t1
                int e01 = t[0] == t[1];//判断t0和t1是否相等
                //第i个字符的修改保存的值在 (i+1) 位置！！！
                //当前不修改字符   （当前位置若为 t1，则前面的 cnt 个t0都可匹配成功
                dp[i+1][j][cnt+e0] = max(dp[i+1][j][cnt+e0], dp[i][j][cnt]+(e1?cnt:0));
                if(j<k) {
                    //将当前字符修改为t0    （若t0和t1相等，则前面 cnt个t0 和当前的t0都可匹配
                    dp[i+1][j+1][cnt+1] = max(dp[i+1][j+1][cnt+1], dp[i][j][cnt]+(e01?cnt:0));
                    //将当前字符修改为t1    （当前位置为t1，则直接添加前面的 cnt个t0 即可
                    dp[i+1][j+1][cnt+e01] = max(dp[i+1][j+1][cnt+e01], dp[i][j][cnt]+cnt);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i <= k;i++) {
        for(int cnt = 0;cnt <= n;cnt++) {
            //状态在 n+1 ！！！
            ans = max(ans, dp[n+1][i][cnt]);//更新最大值
        }
    }
    cout<<ans;
	return 0;
}
