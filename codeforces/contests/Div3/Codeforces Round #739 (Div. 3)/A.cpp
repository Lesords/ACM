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
int a[1005];
int main() {
    int pos = 0;
    for(int i = 1;i;i++) {
        if(i%3==0||(i%10)==3) continue;
        a[++pos] = i;
        if(pos==1000) break;
    }
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<<a[n]<<"\n";
    }
	return 0;
}
