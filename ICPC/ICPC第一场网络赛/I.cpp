#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<sstream>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	fast;
	string s;
	getline(cin, s);
	int A, r;
	cin>>A>>r;
	stringstream ss(s);
	int tmp;
	vector<int> ans;
	while(ss>>tmp) {
		if(abs(tmp-A)<=r) {
			ans.push_back(tmp);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	for(auto v:ans) {
		cout<<v<<" ";
	}
	return 0;
}