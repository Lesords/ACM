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

//题解：其实最大最小值，只会取相邻的两个数
//（出现第三个数时，可能会使最大值降低）

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
ll a[MAXN];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            //计算相邻的乘积，取最大值即可
            if(i>=1) ans = max(ans, a[i]*1ll*a[i-1]);
        }
        cout<<ans<<"\n";
    }
	return 0;
}
