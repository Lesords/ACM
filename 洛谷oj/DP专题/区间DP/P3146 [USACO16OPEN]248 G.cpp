#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：区间dp
//还是以 [左边界,右边界] 为状态
//dp[i][j]为区间[i,j]内可以合成的最大数值
//边界情况为没有合并的时候，值为本身
//每次合并两个区间的时候需要 判断两个区间的值是否相同
//每次合并的时候都可以更新答案，取最大值即可

const int MAXN = 256;
int a[MAXN],dp[MAXN][MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        dp[i][i] = a[i];//边界情况，值为本身
    }
    int ans = 0;
    for(int len = 1;len < n;len++) {            //先长度
        for(int i = 1;i+len <= n;i++) {         //后起点
            int j = i+len;                      //终点可计算
            for(int k = i;k < j;k++) {          //遍历所有中间点
                if(dp[i][k]==dp[k+1][j]) {      //两个区间的值需要相同才可以合并
                    dp[i][j] = max(dp[i][j], dp[i][k]+1);//更新较大值，合并后值+1
                    ans = max(ans, dp[i][j]);   //更新较大值
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
