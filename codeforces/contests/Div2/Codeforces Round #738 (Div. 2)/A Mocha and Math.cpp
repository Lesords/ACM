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

//题解：由于需要使最后的结果最小，并且对应的操作为 &
//那么也就是说，只要有个 位 对应的值为0，那么最优解对应的位置肯定为0
//则对应的结果即为 所有数字的&

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int tmp,ans;//所有数的 与 运算
        for(int i = 1;i <= n;i++) {
            cin>>tmp;
            if(i==1) ans = tmp;//为第一个数字
            else ans &= tmp;//取 & 运算
        }
        cout<<ans<<"\n";
    }
	return 0;
}
