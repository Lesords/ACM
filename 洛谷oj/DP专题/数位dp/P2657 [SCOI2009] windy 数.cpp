#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：数位dp
//计算给定数字所有数位上的值
//然后从高位到低位暴力枚举所有的情况
//当前一个位置上限时，当前最大值为 对应数位 的值
//跳过不满足条件的情况
//由于两个数字差需要为2，但是当前面都为0时
//当前位置可以从0开始遍历，可以转换为前一个数字为 -2（与0差值刚好为2）！！！
//利用 pos,pre 来记录状态，由于pre有负数情况，所以需+3
//记录非受限的情况（非受限情况更多）

int a[20],dp[20][15];//dp[i][j]：从i位置到低位，前一位为pre的数量
//pos为当前位置，lim为当前是否受限，pre为前一个数的值
int dfs(int pos, bool lim, int pre) {
    if(pos==0) return 1;//0为边界，返回1
    //当前非受限，并且对应状态已经计算过，直接返回
    if(!lim&&dp[pos][pre+3]!=-1) return dp[pos][pre+3];
    int ans = 0;//记录结果
    int siz = lim?a[pos]:9;//计算当前位置的范围
    for(int i = 0;i <= siz;i++) {//遍历所有情况
        if(abs(pre-i)<2) continue;//跳过不满足条件的
        //前一位为-2（0）并且当前也为0，那么对应值为-2，否则为i
        int now = (pre==-2&&i==0)?-2:i;
        //lim参数：当前受限并且当前为最大值a[pos]时为受限（值为true）
        ans += dfs(pos-1, lim&&i==a[pos], now);
    }
    //记录非受限的情况
    if(!lim) dp[pos][pre+3] = ans;
    return ans;
}
int solve(int val) {//计算val的所有数位的值
    int top = 0;//从1开始记录
    while(val) {
        a[++top] = val%10;
        val /= 10;
    }
    //当前位置为top，受限，并且前一个值为-2（表示当前可以从0开始）
    return dfs(top, 1, -2);
}
int main() {
    memset(dp, -1, sizeof(dp));//初始化为-1
    int a,b;
    cin>>a>>b;
    cout<<solve(b) - solve(a-1);//差值即为区间内的数量
    return 0;
}
