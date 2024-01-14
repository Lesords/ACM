#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//题解：数位dp
//预处理所有二进制位对应的十进制值
//然后在dfs过程中，添加一个当前函数值的参数
//以 当前位置到最低位的函数所需的函数值 为dp第二维状态
//即 要求值all - 当前值sum
//因为sum为 最高位到前一个位置 的值，所以不便做状态！！！
//如果当前函数值超过要求值，直接返回0！！！

int val[15],a[15],dp[15][10000];//值的范围：(1<<10)*9 = 1024*9
//val[i]:记录二进制对应位置的值，即 1<<(i-1)
//a数组记录给定数字的所有数位上的值
//dp[i][j]:为非受限时，从i位置到低位中，对应位置函数值为j的情况数
int all;//记录限定的函数值
int cal(int v) {//计算v的函数值
    if(v<10) return v;//小于10为边界，直接返回
    return cal(v/10)*2+v%10;
}
//pos为当前位置，lim为当前位置是否受限，sum为当前对应函数值
int dfs(int pos, bool lim, int sum) {
    if(pos==0) {//边界位置，判断函数值是否小于对应值
        return sum<=all;
    }
    //超过对应函数值的，直接返回0
    if(sum>all) return 0;
    //非受限并且当前状态已经计算过，直接返回
    if(!lim&&dp[pos][all-sum]) return dp[pos][all-sum];
    int ans = 0;//累加结果
    int siz = lim?a[pos]:9;//当前位置的范围
    for(int i = 0;i <= siz;i++) {//遍历所有范围
        //lim参数：当前受限并且值为a[pos]
        //sum参数：累加当前位置 pos 的对应值 i
        ans += dfs(pos-1, lim&&i==a[pos], sum+i*val[pos]);
    }
    //非受限，记录当前状态值
    if(!lim) dp[pos][all-sum] = ans;
    return ans;
}
int solve(int v) {//计算v的所有数位的值
    int pos = 0;
    while(v) {//从1开始记录
        a[++pos] = v%10;
        v /= 10;
    }
    //当前位置为pos，当前受限，函数值为0
    return dfs(pos, 1, 0);
}
int main() {
    //计算二进制对应位置的值
    for(int i = 1;i <= 15;i++) val[i] = 1<<(i-1);
    int t;
    scanf("%d", &t);
    for(int cas = 1;cas <= t;cas++) {
        int a,b;
        scanf("%d%d", &a,&b);
        all = cal(a);//计算限定的函数值
        printf("Case #%d: %d\n", cas, solve(b));
    }
    return 0;
}
