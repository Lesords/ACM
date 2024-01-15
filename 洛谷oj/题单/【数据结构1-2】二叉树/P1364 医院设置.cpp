#include<iostream>//ac
#include<cstring>
#include<set>
#include<map>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：floyd计算最短路路，复杂度O(n^3)
//然后暴力枚举每个点为医院所需要的距离和，取最小值

const int MAXN = 105;
int a[MAXN][MAXN],num[MAXN];//a存图，num记录每个城市的居民人数
int main() {
    int n,cnt = 0;
    cin>>n;
    memset(a,0x3f,sizeof(a));//初始化为最大值
    for(int i = 1;i <= n;i++) {
        a[i][i] = 0;//自己到达自己的值为0
        int w,u,v;
        cin>>w>>u>>v;
        num[i] = w;//记录当前城市的人数
        if(u) {//若u存在，则存边
            a[i][u] = a[u][i] = 1;
        }
        if(v) {//若v存在，则存边
            a[i][v] = a[v][i] = 1;
        }
    }
    for(int k = 1;k <= n;k++) {//floyd计算最短路
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                a[i][j] = a[j][i] = min(a[i][j], a[i][k]+a[k][j]);
            }
        }
    }
    int ans = INF;
    for(int i = 1;i <= n;i++) {
        int tmp = 0;//计算以i为医院居民的路程之和
        for(int j = 1;j <= n;j++) {
            tmp += a[i][j]*num[j];//j城市居民走到i医院，人数为num[j]！！！
        }
        ans = min(ans, tmp);
    }
    cout<<ans;
    return 0;
}

