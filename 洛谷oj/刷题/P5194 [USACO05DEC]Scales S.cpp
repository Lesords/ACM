#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：dfs遍历来选择砝码，然后利用前缀和判定来剪枝

const int MAXN = 1e3+5;
ll n,c,a[MAXN],sum[MAXN],ans;//sum为前缀和数组，a为原数组
void dfs(ll pos,ll val) {//pos为当前位置，val为当前重量
    if(val>c) return;//重量超了则跳过
    if(sum[pos-1]+val<=c) {//前面全部拿了满足条件，则更新答案，剪枝！！！
        ans = max(ans, sum[pos-1]+val);
        return;
    }
    ans = max(ans, val);//更新答案
    for(int i = 1;i < pos;i++) {//遍历前面还未选择的砝码
        dfs(i, val+a[i]);//更新位置，和对应值（只选择对应位置的砝码！！！
    }
}
int main() {
    cin>>n>>c;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];//前缀和处理
    }
    dfs(n+1,0);
    cout<<ans;
    return 0;
}
