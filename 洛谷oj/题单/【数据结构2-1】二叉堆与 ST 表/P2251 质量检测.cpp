#include<iostream>//ac
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 1e6+6;
int a[MAXN],f[MAXN][25];
int n,m;
void ST_init() {
    memset(f,0x3f,sizeof(f));//初始化为最大值
    for(int i = 1;i <= n;i++) f[i][0] = a[i];//边界值
    int siz = log(n)/log(2);//倍增长度
    for(int i = 1;i <= siz;i++) {
        for(int j = 1;j+(1<<i)-1 <= n;j++) {
            int len = 1<<(i-1);
            //注意j和i的顺序！！！
            //j是起点，i是区间长度
            f[j][i] = min(f[j][i-1],f[j+len][i-1]);
        }
    }
}
int query(int l,int r) {
    int siz = log(r-l+1)/log(2);
    return min(f[l][siz],f[r-(1<<siz)+1][siz]);
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    ST_init();
    for(int i = 1;i <= n-m+1;i++) {//输出(n-m+1)个区间长度为m的最小值即可
        cout<<query(i,i+m-1)<<"\n";
    }
    return 0;
}
