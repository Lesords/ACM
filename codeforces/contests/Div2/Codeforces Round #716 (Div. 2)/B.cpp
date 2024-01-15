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

//题解：由于数组的值不能炒股2^k-1，所以数组的值只有 k个二进制位
//所有位的 与运算 的结果都需要为0， 所以每个二进制位都至少需要一个 0
//数组的总和必须为最大，所以每个二进制位只能有一个0（多了总和会减少
//那么可以将数组的值初始化为，全部二进制位置上的值为1
//将每个二进制上的值修改一个
//由于数组总数有n个，二进制位有k个
//所以结果为 n*n*n*···*n*n  =  n^k  （k个位置，每个位置都有n个选项

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    int T;
    cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        ll ans = 1;
        for(int i = 1;i <= k;i++) {//计算n^k，记得取模
            ans = (ans*n)%MOD;
        }
        cout<<ans<<"\n";
    }
	return 0;
}
