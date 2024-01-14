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
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        if(n==1) {
            cout<<"No!\n";
            continue;
        }
        if(n==k&&n==2) {
            cout<<"No!\n";
            continue;
        }
        if(n==k) {
            cout<<"Yes!\n";
            continue;
        }
        if(k&1) cout<<"Yes!\n";
        else cout<<"No!\n";
    }
	return 0;
}
