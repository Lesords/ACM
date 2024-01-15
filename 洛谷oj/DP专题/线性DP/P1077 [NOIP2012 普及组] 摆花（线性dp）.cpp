#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：线性dp
//利用 当前位置的花和已经选择的数量 为状态
//f[i][j]:在当前位置i（第i种花），并且已经选择了j盆花的方案数
//对于每个位置有 a[i] 个选择
//转移方程为 f[i][j] += f[i-1][j-k] （即当前选择了k个i位置的花
//注意：记得判断已选择数量是否大于等于当前选择的数量

const int MAXN = 105;
const int MOD = 1000007;
int a[MAXN],f[MAXN][MAXN];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    f[0][0] = 1;//边界状态
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= m;j++) {
            for(int k = 0;k <= a[i];k++) {//当前选择的情况
                if(j>=k) {
                    f[i][j] = (f[i][j]+f[i-1][j-k])%MOD;
                }
            }
        }
    }
    cout<<f[n][m];
    return 0;
}
