#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

//题意：计算期望，并且期望结果*n
//期望为：所有可能值按照概率加权的和
//样例：4  1 2 3 4
//删除对应位置的值为：1 2 2 1
//则期望为 1 * 2/4 + 2 * 2/4 = 6/4
//输出结果为 6/4 * 4 = 6
//也就是说题目求的是删除每个位置后最大差值的总和（概率一样，可被n消掉）

//题解：利用前缀和和后缀和思想优化两个数的最大差值
//pre[i]：i及i前 两数差的最大值
//suf[i]：i及i后 两数差的最大值
//然后遍历所有位置，判断将当前位置删除后的最大差值，累加
//注意特判第一位置和最后一个位置
//中间部分需要和被删除位置的左右两个剩余位置再次比较

const int MAXN = 1e5+5;
ll pre[MAXN],suf[MAXN],a[MAXN];
ll cal(int pos,int val) {//计算pos和pos+val位置的差值
    return llabs(a[pos]-a[pos+val]);
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        for(int i = 1;i <= n;i++) {
            scanf("%lld", &a[i]);
//            pre[i] = suf[i] = 0;//初始化为0
        }
        for(int i = 2;i <= n;i++) {//从2开始计算
            pre[i] = max(pre[i-1], cal(i, -1));
        }
        suf[n] = 0;//也可以直接使n的位置为0！！！
        for(int i = n-1;i >= 1;i--) {//倒着，从n-1开始计算
            suf[i] = max(suf[i+1], cal(i, 1));
        }
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            if(i==1) ans += suf[i+1];//特判第一个位置
            else if(i==n) ans += pre[i-1];//特判最后一个位置
            else ans += max(max(pre[i-1], suf[i+1]), cal(i+1, -2));
            //删除i位置，剩余 i-1,i+1 两个位置，需要再比较一次！！！
        }
        cout<<ans<<"\n";
    }
    return 0;
}
