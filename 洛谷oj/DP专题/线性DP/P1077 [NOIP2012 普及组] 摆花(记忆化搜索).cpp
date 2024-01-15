#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：记忆化搜索
//利用 当前位置的花和已摆放的数量 当成状态
//那么每次决策为当前位置可以选择的花，逐个数量选择
//由于搜索是从前往后搜的
//所以对于f[i][j]为：从i位置的话（第i种花）开始往后摆m-j个花的方案数

const int MAXN = 105;
const int MOD = 1000007;
int n,m;                    //n种花，摆m盆
int a[MAXN],f[MAXN][MAXN];  //a为每种花的限制数量
int dfs(int pos,int num) {  //当前位置在pos，并且已经选择了num个花
    if(num>m) return 0;     //超过m盆直接跳过
    if(num==m) return 1;    //等于m盆表示当前选择为一次方案数
    if(pos>n) return 0;     //超过n的位置，就不需要继续摆了
    if(f[pos][num]) return f[pos][num];     //已计算过，直接返回
    int ans = 0;
    for(int i = 0;i <= a[pos];i++) {        //遍历所有选择的情况数
        ans = (ans+dfs(pos+1,num+i))%MOD;   //当前累加
    }
    return f[pos][num] = ans;               //返回并赋值
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    cout<<dfs(1,0);
    return 0;
}
