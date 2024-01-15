#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e6+5;
const int MOD = 10000;
int f[MAXN],d[MAXN];//f[i]：填满i长的方案数，d[i]：在i位置放L型砖的方案数（单方向）
int main() {
    //长度为0和1的方案数都为1，长度为1的齿轮方案数也为1！！！
    f[0] = f[1] = d[1] = 1;
    int n;
    cin>>n;
    for(int i = 2;i <= n;i++) {//公式推导见PPT
        f[i] = (f[i-1]+f[i-2]+d[i-2]*2)%MOD;
        d[i] = (f[i-1]+d[i-1])%MOD;
    }
    cout<<f[n];
    return 0;
}
