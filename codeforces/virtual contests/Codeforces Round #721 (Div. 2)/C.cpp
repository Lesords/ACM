#include<iostream>//?
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
ll C(int n,int m) {
    int ans = 1;
    for(int i = (n-m+1);i <= n;i++) ans *= i;
    for(int i = 1;i <= m;i++) ans /= i;
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        map<int,int> num;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            int tmp;cin>>tmp;
            num[tmp]++;
        }
        ll ans = 0;
        for(auto v:num) {
            int tmp = v.second;
            if(tmp<2) continue;
            cout<<tmp<<" ";
            ans += C(tmp,2);
        }
        cout<<"\n";
        cout<<ans<<"\n";
    }
	return 0;
}
