#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//题解：线性dp
//由于任务有延续时间，所以从前往后表示状态的话，即dp[i]为1-i间的空余时间
//会不好计算，因为当前位置i无法记录结束时间对后面的影响
//所以可以从后往前计算，即dp[i]为i-n间的空余时间
//初始化所有位置的值为0，因为要求最大值
//转移：
//如果当前时刻没有任务 dp[i] = dp[i+1]+1
//否则取所有任务完成后的空闲时间的最小值 Min(ALL(dp[i+time]))
//目的状态：dp[1]
//技巧：直接用vector存储每个时刻的任务持续时间，这样就不用在排序了

const int MAXN = 1e4+5;
vector<int> g[MAXN];//存储对应时刻的任务的持续时间
int dp[MAXN];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= k;i++) {
        int p,t;
        cin>>p>>t;
        g[p].push_back(t);//记录p时刻的任务持续时间为t
    }
    for(int i = n;i >= 1;i--) {//倒序计算
        //当前时刻无任务，则直接更新
        if(g[i].empty()) dp[i] = dp[i+1]+1;
        else {
            //否则取所有任务完成后的空闲时间的最小值
            for(auto v:g[i]) {//遍历当前时刻开始的所有任务
                dp[i] = max(dp[i], dp[i+v]);
            }
        }
    }
    cout<<dp[1];
    return 0;
}
