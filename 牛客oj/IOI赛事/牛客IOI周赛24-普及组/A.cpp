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
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
    fast;
    int a,b;
    cin>>a>>b;
    ll ansA = 0,ansB = 0;
    ll val = 1;
    while(a) {
        if(a&1) {
            ansA += val;
        }
        val *= 10;
        a >>= 1;
    }
    val = 1;
    while(b) {
        if(b&1) {
            ansB += val;
        }
        val *= 10;
        b >>= 1;
    }
    cout<<ansA+ansB;
	return 0;
}
