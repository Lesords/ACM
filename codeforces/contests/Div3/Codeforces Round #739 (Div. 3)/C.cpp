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
    fast;
    int t;
    cin>>t;
    while(t--) {
        int k;
        cin>>k;
        int siz = sqrt(k);
        int val = siz*siz;//分割为对应的 n*n + res（最后一列和最后一行）
        if(k==siz*siz) {
            cout<<siz<<" 1\n";
            continue;
        }
        int dis = k-val,x,y;
        if(dis<=siz+1) {
            cout<<dis<<" "<<siz+1<<"\n";
        }
        else {
            dis -= siz;
            cout<<siz+1<<" "<<siz+1-dis+1<<"\n";
        }
    }
	return 0;
}
