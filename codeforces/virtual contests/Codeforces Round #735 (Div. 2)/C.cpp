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

//题解：由于异或中有 a^b = c 推出 a^c = b

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        m++;
        int ans = 0;
        for(int i = 30;i >= 0&&n < m;i--) {
            if((1<<i&n)&&(1<<i&m)) continue;
            if((1<<i&m)) {
                ans |= 1<<i, n |= 1<<i;
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
