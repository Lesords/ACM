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
string s[66];
int len[66];
int main() {
    for(int i = 0;i <= 60;i++) {//计算所有位置的值（到1e18，因为1e9存在可直接加9位的情况
        s[i] = to_string(1ll<<i);
        len[i] = s[i].size();
    }
    fast;
    int t;
    cin>>t;
    while(t--) {
        string a;
        cin>>a;
        int ans = INF;
        int siz = a.size();
        for(int i = 0;i <= 60;i++) {
            int pos = 0, posa = 0, del = 0;
            while(posa < siz) {
                if(a[posa++] == s[i][pos]) {
                    pos++;
                    if(pos==len[i]) break;
                }
                else del++;
            }
            ans = min(ans, (len[i]-pos) + (del+siz-posa));
        }
        cout<<ans<<"\n";
    }
	return 0;
}
