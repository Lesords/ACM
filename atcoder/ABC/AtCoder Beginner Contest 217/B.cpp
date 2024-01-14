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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
string s[5] = {
	"ABC", "ARC", "AGC", "AHC"
};
int main() {
	string n[5];
	set<string> st;
	for(int i = 1;i <= 3;i++) {
		cin>>n[i];
		st.insert(n[i]);
	}
	for(int i = 0;i < 4;i++) {
		if(st.find(s[i])==st.end()) {
			cout<<s[i]<<"\n";
			return 0;
		}
	}
    return 0;
}