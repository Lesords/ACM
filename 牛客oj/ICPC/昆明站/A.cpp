#include<iostream>//wa
#include<cstring>
#include<cstdlib>
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
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
const int MAXN = 5e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
vector<int> a;
vector<int> c;
int vis[MAXN];
int main() {
	int n, k;
	string s;
	cin >> n >> k;
	cin >> s;
	int ans = 0;
	for(int i = 0;i < s.size();i++) {
		if(s[i]=='a') a.push_back(i);
		if(s[i]=='c') {
			if(i&&s[i-1]=='a') a.pop_back(), vis[i]=vis[i-1]=1, ans++;
			else {
				c.push_back(i);
			}
		}
	}
	for(auto v:a) {
		if(k==0) break;
		if(vis[v+1]) continue;
		if(v+1==s.size()) break;
		vis[v+1] = 1;
		ans++;
		s[v+1] = 'c';
		k--;
	}
	for(auto v:c) {
		if(k==0) continue;
		if(v==0) continue;
		if(vis[v-1]) continue;
		vis[v-1] = 1;
		ans++;
		s[v-1] = 'a';
		k--;
	}
	if(k>=2) {
		for(int i = 1;i < s.size();i++) {
			if(vis[i]||vis[i-1]) continue;
			vis[i] = vis[i-1] = 1;
			s[i] = 'c', s[i-1] = 'a';
			ans++;
		}
	}
	cout << ans << "\n" << s << "\n";
    return 0;
}
