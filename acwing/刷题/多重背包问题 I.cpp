#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：多重背包可以将多个i种的物品，理解成独立的Ci个物品
//然后转换成01背包来计算

const int MAXN = 1010;
int v[MAXN],w[MAXN],s[MAXN],f[MAXN];
int main() {
    int n,m;
    cin>>n>>m;//没有负数，所以不需要初始化为较小值
    for(int i = 1;i <= n;i++) cin>>v[i]>>w[i]>>s[i];
    for(int i = 1;i <= n;i++) {
        for(int k = 1;k <= s[i];k++) {
            for(int j = m;j >= v[i];j--) {
                f[j] = max(f[j], f[j-v[i]]+ w[i]);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= m;i++) {//统计最大值
        ans = max(ans, f[i]);
    }
    cout<<ans;
    return 0;
}
