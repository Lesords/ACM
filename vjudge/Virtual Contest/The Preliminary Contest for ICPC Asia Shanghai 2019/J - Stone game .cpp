#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

//题意：从给定集合中选出一个子集
//使得子集大于等于剩余集合的总和，并且子集中任选一个删除都小于等于剩余集合的总和
//那么对于集合进行从小到大排序，使得每次操作时，当前值都为集合最小值
//令 dp[i] 表示集合总和为i的方案数
//那么对于每个数字来说，都有选和不选两个方案，即可套用01背包
//边界状态：dp[0] = 1，其他为0 即都不选的情况为1
//由于是计数，所以转移过程是累加
//计算结果的时候，需要判断子集条件是否满足

const int MAXN = 305;
const int MOD = 1e9+7;
ll a[MAXN],dp[MAXN*500];
bool cmp(ll a,ll b) {//从大到小排序
    return a>b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        ll sum = 0,ans = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            sum += a[i];//累加，求原集合总和
        }
        sort(a+1,a+n+1,cmp);//从大到小排序
        memset(dp, 0, sizeof(dp));//初始化为0
        dp[0] = 1;//边界为1
        for(int i = 1;i <= n;i++) {
            for(int j = sum;j >= a[i];j--) {//倒序为01背包
                dp[j] = (dp[j]+dp[j-a[i]])%MOD;//累加，即选和不选，记得取模
                if(j>=sum-j&&j-a[i]<=sum-j) {//子集满足条件！！！
                    ans = (ans+dp[j-a[i]])%MOD;
                    //只添加选择的情况，因为需要判断当前不选是否小于等于剩余集合！！！
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
