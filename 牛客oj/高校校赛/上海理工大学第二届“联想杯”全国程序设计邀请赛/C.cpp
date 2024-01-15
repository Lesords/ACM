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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
string s[MAXN];
map<string,int> num;
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>s[i];
        num[s[i]]++;
    }
    int ans = num["cat"];
    ans += min(num["c"],num["at"]);
    num["c"] -= min(num["c"],num["at"]);
    ans += min(num["ca"],num["t"]);
    num["t"] -= min(num["ca"],num["t"]);
    ans += min(min(num["c"],num["a"]),num["t"]);
    cout<<ans;
	return 0;
}
