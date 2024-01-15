// Problem: C. Slay the Dragon
// Contest: Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL: https://codeforces.ml/contest/1574/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-20 23:10:43

#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
using namespace std;

//题解：贪心
//可以将所有的英雄按照能力从小到大排序
//由于击杀龙的英雄只需要一个，所以尽量使击杀龙的英雄的能力值相对较小
//那么剩余的英雄的防御力就会越大

//由于可能出现一个能力值较小的英雄击杀龙的操作数会更小
//（直接击杀龙的能力过大，可对防守作出更多贡献）
//所以需要将范围内的较小值和较大值都计算一遍，然后取最小值

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
ll a[MAXN];
int main() {
	fast;//tle!!!
    int n;
    cin>>n;
    ll sum = 0;
    for(int i = 1;i <= n;i++) {
    	cin>>a[i];
    	sum += a[i];//累加和，这样 防御的能力值和 = 总和 - 击杀龙的英雄能力
    }
    sort(a+1, a+n+1);//从小到大排序
    int m;
    cin>>m;
    for(int i = 1;i <= m;i++) {
    	ll x, y;
    	cin>>x>>y;
    	int pos = lower_bound(a+1, a+n+1, x) - a;
    	ll ans = 0;
    	if(pos==n+1) {//没有英雄可以独立击杀龙
    		ans = (x-a[n])+max(y- (sum-a[n]), 0ll);
    		cout<<ans<<"\n";
    	}
    	else if(pos==1) {//所有英雄都可以独立击杀龙
    		ans = max(y- (sum-a[1]), 0ll);
    		cout<<ans<<"\n";
    	}
    	else {//有可以击杀的也有不可以击杀的，所以两种情况都计算
    		ll tmp = max(y - (sum-a[pos]), 0ll);
    		ans = tmp;
    		tmp = max(y - (sum-a[pos-1]), 0ll) + x - a[pos-1];
    		ans = min(ans, tmp);
    		cout<<ans<<"\n";
    	}
    }
    return 0;
}
