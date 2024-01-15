// Problem: C. Get an Even String
// Contest: Codeforces - Codeforces Round #780 (Div. 3)
// URL: https://codeforces.ml/contest/1660/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2022-03-31 22:39:44

#include<iostream>
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
bool is_even(string& s) {
	for(int i = 0;i < s.size();i += 2) {
		if(s[i] != s[i+1]) return false;
	}
	return true;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
    	string s;
    	cin >> s;
    	if(is_even(s)) {
    		cout << "0\n";
    		continue;
    	}
    	map<char, int> mp;
    	for(int i = 0;i < s.size();i++) mp[s[i]]++;
    	string ss = "";
    	int ans = 0;
    	for(int i = 0;i < s.size();i++) {
    		if(mp[s[i]] == 1) {
    			ans++;
    			mp.erase(s[i]);
    			continue;
    		}
    		ss += s[i];
    	}
    	s = ss;
    	if(is_even(s)) {
    		cout << ans << "\n";
    		continue;
    	}
    	
    	
    	for(auto val:mp) {
    		cout << val.fi << " " << val.se << "\n";
    	}
    	cout << "\n";
    	cout << ans << "\n";
    }
    return 0;
}
