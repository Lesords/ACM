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
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：结论 (x+1)^2 - (x+2)^2 - (x+3)^2 + (x+4)^2 = 4
// 1: 1
// 2: -1-4-9+16 = 2
// 3: -1+4 = 3
// 4: 1-4-9+16 = 4

const int MAXN = 1e3;
const int MOD = 1e9+7;
string s[5] = {"", "1", "0001", "01", "1001"};
int main() {
	int t;
	cin>>t;
	while(t--) {
		int n;
		string ans = "";
		cin>>n;
		ans += s[n%4];
		for(int i = 1;i <= n/4;i++) ans += s[4];
		cout<<ans.size()<<"\n"<<ans<<"\n";
	}
    return 0;
}
