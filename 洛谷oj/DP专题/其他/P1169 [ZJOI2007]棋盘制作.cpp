#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

//题解：悬线法dp
//对于每个格子，分别预处理可以向左、向右、向上扩大的大小
//然后计算每个格子，向上处理，以当前点为基准，左右可以扩张的最大范围
//也就是说如果上一行和当前位置满足条件（不满足条件，不用扩张！！！）
//需要更新对应的向左和向右的大小（也就是对于当前向上悬线，可以向左右扩张的大小）
//那么对于当前格子而言，最大矩阵结果即为 向上扩张*（向左+向右-1）
//如果向左和向右包括本身的话，需要-1；不包括的话，需要+1
//对于正方形来说，只需要满足 向上扩张 等于 （向左+向右-1），即取min即可

const int MAXN = 2e3+5;
ll l[MAXN][MAXN], r[MAXN][MAXN], u[MAXN][MAXN];//l向左，r向右，u向上
int a[MAXN][MAXN];
ll two(ll x) { return x*x;}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin>>a[i][j];
            l[i][j] = r[i][j] = u[i][j] = 1;//预处理所有位置为1
        }
    }
    //计算向左扩张的大小
    for(int i = 1;i <= n;i++) {
        for(int j = 2;j <= m;j++) {//不包括第一列
            if(a[i][j]!=a[i][j-1]) {//需要满足不相等的情况！！！
                l[i][j] = l[i][j-1]+1;//包括本身
            }
        }
    }
    //计算向右扩张大小
    for(int i = 1;i <= n;i++) {
        for(int j = m-1;j >= 1;j--) {//倒着计算，不包括最后一列
            if(a[i][j]!=a[i][j+1]) {//需要满足不相等的情况！！！
                r[i][j] = r[i][j+1]+1;//包括本身
            }
        }
    }
    //计算向上扩张的大小
    for(int i = 2;i <= n;i++) {//不包括第一行
        for(int j = 1;j <= m;j++) {
            if(a[i][j]!=a[i-1][j]) {//需要满足不相等的情况！！！
                u[i][j] = u[i-1][j]+1;
            }
        }
    }
    ll ans1 = 1,ans2 = 1;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {//计算所有格子，悬线可以横移的矩阵大小
            //不为第一行，且满足条件，才需要更新
            //切记，要满足条件，否则可能出现不更新值反而大的情况！！！
            if(i>1&&a[i][j]!=a[i-1][j]) {
                l[i][j] = min(l[i][j], l[i-1][j]);
                r[i][j] = min(r[i][j], r[i-1][j]);
            }
            //正方形
            ans1 = max(ans1, two(min(u[i][j], l[i][j]+r[i][j]-1)));
            //矩形
            ans2 = max(ans2, u[i][j]*(l[i][j]+r[i][j]-1));
        }
    }
    cout<<ans1<<"\n"<<ans2<<"\n";
    return 0;
}
