#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：数位dp
//计算给定值的所有数位上的值
//然后从高位开始暴力枚举每个位置上的值
//判断前一个位置是否受限，然后来确定当前位置值的范围
//跳过不符合条件的情况
//然后记录对应状态的数量（记忆化搜索）
//由于遍历过程中，不受限的情况更多，所以记录的时候选择不受限的
//不受限的情况和受限情况的值不一致！！！

const int MAXN = 1e5+5;
int a[20],dp[20][2];
//dp[i][j]中：i表示当前位置（不受限），j表示前一个是否为6
//dp[i][0]:从i位置到最低位中，i前面不为6的情况数
//dp[i][1]:从i位置到最低位中，i前面为6的情况数

//pos为当前位置，lim为当前位是否受限，pre为前一个是否为6
int dfs(int pos,bool lim,bool pre) {
    if(pos==0) return 1;//0位置，表示所有位都遍历结束，返回1
    //当前位置不受限，并且对应状态已经计算过了，直接返回值
    //因为不受限的情况更多，运行的更快！！！
    if(!lim&&dp[pos][pre]!=-1) return dp[pos][pre];
    int ans = 0;//记录结果
    int siz = lim?a[pos]:9;//判断当前位置的范围（是否受限）
    for(int i = 0;i <= siz;i++) {//遍历所有值
        if(i==4) continue;//4不满足条件
        if(pre&&i==2) continue;//前一位为6，当前为2，不满足条件
        //累加满足条件的情况
        //lim参数：前一个位置受限并且当前值为最大值a[pos]时为受限（true）
        ans += dfs(pos-1, lim&&i==a[pos], i==6);//位置-1，判断当前值是否为6
    }
    //不受限，则记录当前状态的值
    if(!lim) dp[pos][pre] = ans;
    return ans;
}
int solve(int val) {//计算val所有数位的值
    int pos = 0;//从1开始计算
    while(val) {
        a[++pos] = val%10;
        val /= 10;
    }
    return dfs(pos, 1, 0);//初始情况位置为pos，有受限，当前位设为0
}
int main() {
    int n,m;
    memset(dp, -1, sizeof(dp));//初始化为-1，方便记忆化
    while(scanf("%d%d",&n,&m)&&n+m) {
        cout<<solve(m)-solve(n-1)<<"\n";//前缀和相减即为区间值
    }
    return 0;
}
