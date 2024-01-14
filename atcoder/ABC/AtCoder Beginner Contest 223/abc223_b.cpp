// Problem: B - String Shifting
// Contest: AtCoder - AtCoder Beginner Contest 223
// URL: https://atcoder.jp/contests/abc223/tasks/abc223_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-17 20:02:44

#include<iostream>//ac
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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int main() {
	string s;
	vector<string> ans;
	cin >> s;
	int len = s.size();
	s += s;
	for(int i = 0;i < len;i++) {
		ans.push_back(s.substr(i, len));
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << "\n";
	cout << ans[ans.size()-1] << "\n";
    return 0;
}
