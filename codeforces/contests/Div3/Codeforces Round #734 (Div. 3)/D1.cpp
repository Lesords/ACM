#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：由于垂直摆放和水平摆放最后会铺满整个表格
//所以可以计算水平摆放的数量范围区间
//如果行数为奇数，那么至少有一行得横向摆放（m/2个）
//如果列数为奇数，那么至少有一列需要垂直摆放（n/2个），对应水平个数为 n*m/2 -(n/2) 个
//因为除了垂直摆放，剩余都是水平摆放！！！

//扣除一行的摆放数量，剩余的垂直摆放数量一定要为2的倍数
//这样对应的高度才能垂直摆放


const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,m,k;
        cin>>n>>m>>k;
        int min_h = n%2?m/2:0;//最少的水平摆放数量
        int max_h = n*m/2 - (m%2?n/2:0);//最多的水平摆放数量
        //水平数量需要在范围内，并且剩余数必须为2的倍数！！！
        if(min_h<=k&&k<=max_h&&(k-min_h)%2==0) {
            cout<<"YES\n";
        }
        else cout<<"NO\n";
    }
    return 0;
}
