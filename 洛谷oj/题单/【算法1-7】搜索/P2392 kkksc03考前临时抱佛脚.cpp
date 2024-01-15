#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：四种科目可以理解为四种数据，每种的解法一致
//对于每个科目的考试可以放在左边也可以放在右边，可以理解为01背包
//也就是说对于左边可以选当前科目也可以不选，那么对应的最优空间应为 总和/2
//即背包的体积为 总和/2，每个科目占用空间和价格都为消耗的时间（val）
//最后dp所求的可能为较小的一边，所以添加的结果需为另一边的值

int num[5],val[25],dp[1205];
int main() {
    for(int i = 1;i <= 4;i++) cin>>num[i];//四种科目对应数量
    int ans = 0;
    for(int i = 1;i <= 4;i++) {
        int sum = 0;//初始化为0
        for(int j = 1;j <= num[i];j++) cin>>val[j],sum+=val[j];//读入科目消耗时间，并计算总和
        for(int j = 1;j <= num[i];j++) {//遍历所有科目
            for(int k = sum/2;k >= val[j];k--) {//在可放入的背包体积范围内判断是否需要选择
                dp[k] = max(dp[k],dp[k-val[j]]+val[j]);//选与不选取较大值
            }
        }
        //左边最大值为 总和/2 ，所以取另一边可行
        ans += sum-dp[sum/2];//取另外一边（较大值）
        for(int i = sum/2;i >= 1;i--) dp[i] = 0;//清零
    }
    cout<<ans<<endl;
    return 0;
}
