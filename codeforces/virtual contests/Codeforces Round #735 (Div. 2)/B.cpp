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
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：由于所有的 ai 都小于n
//那么对于 ai|aj 而言，最大值为 2*n，最小值为0
//对于 i*j 来说，最大值为 (n-1) * n
//则对于（n-1,n)来说有
//最大值情况： (n-1)*n - k*0 = (n-1)*n
//最小值情况： (n-1)*n - k*(2n)
//对于其他位置 (i,n) 而言，要想值大于 (n-1,n)
//那么得有 ai|aj = 0，即为 i*n
//则存在i位置大于 n-1 位置的可能为（i尽量大，n-1尽量小）
// i*n > (n-1)*n - k*(2n)
// i > (n-1) - 2*k
//即 i >= n - 2k
//也就是说，我们只需要从 n-2k 位置开始遍历即可
//注意 n-2k 若为负数，需要设为1！！！


const int MAXN = 2e5+5;
const int MOD = 1e9+7;
ll a[MAXN];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        ll ans = -INF;
        int l = max(1, n-2*k);//位置不能为负数！！！
        for(int i = n;i >= l;i--) {
            for(int j = l;j < i;j++) {//从l开始遍历即可
                ans = max(ans, i*1ll*j-k*1ll*(a[i]|a[j]));
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
