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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：动态规划，对于每个位置，要么选要么不选
//对于选和不选都有两种情况：下一个状态在当前行或者在下一行（对应的cnt数量不一样）
//注意：cnt选择的数量不能超过每行的一半！！！
//从前往后推，那么dp[n][1][0][0]即为答案
//dp[i][j][cnt][rem]：在i和j位置之前，当前行已经选择了cnt个并且余数为rem的最大总和

const int MAXN = 75;
int a[MAXN][MAXN],dp[MAXN][MAXN][MAXN][MAXN];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin>>a[i][j];
    }
    memset(dp,-1,sizeof(dp));//初始化为-1，表示状态不可达
    dp[1][1][0][0] = 0;//初始化起点为0
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            int tx = (j==m)?i+1:i;//如果在行末，需要移到下一行行首
            int ty = (j==m)?1:j+1;
            for(int cnt = 0;cnt <= m/2;cnt++) {
                for(int rem = 0;rem < k;rem++) {
                    if(dp[i][j][cnt][rem]==-1) continue;//跳过状态不存在的情况
                    //不选当前位置
                    if(i!=tx) {//不同行，cnt需为0
                        dp[tx][ty][0][rem] = max(dp[tx][ty][0][rem], dp[i][j][cnt][rem]);
                    }
                    else {//同行
                        dp[tx][ty][cnt][rem] = max(dp[tx][ty][cnt][rem], dp[i][j][cnt][rem]);
                    }
                    //选当前位置
                    if(cnt+1 <= m/2) {//当前选了之后不要超过m/2！！！
                        int re = (rem+a[i][j])%k;//更新余数
                        if(i!=tx) {//不同行，cnt需为0
                            dp[tx][ty][0][re] = max(dp[tx][ty][0][re], dp[i][j][cnt][rem]+a[i][j]);
                        }
                        else {//同行
                            dp[tx][ty][cnt+1][re] = max(dp[tx][ty][cnt+1][re],dp[i][j][cnt][rem]+a[i][j]);
                        }
                    }
                }
            }
        }
    }
    cout<<dp[n+1][1][0][0];
	return 0;
}
