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
map<pii,ll> sum;
int nextt[4][2] = {-1,0, 1,0, 0,-1, 0,1};//U D L R
int treeX[MAXN], treeY[MAXN];
int x[MAXN],y[MAXN];
int main() {
	fast;
    int t;
    cin>>t;
    while(t--) {
    	sum.clear();
    	int num;
    	string s;
    	cin>>num>>s;
    	for(int i = 0;i < num;i++) x[i] = y[i] = 0;
    	for(int i = 0;i < num;i++) {
    		if(s[i]=='L') x[i] = -1;
    		else if(s[i]=='R') x[i] = 1;
    		else if(s[i]=='U') y[i] = -1;
    		else if(s[i]=='D') y[i] = 1;
    	}
    	int nx = 0, ny = 0;
    	pii p,re;
    	ll ans = 0;
    	for(int i = 0;i < num;i++) {
    		nx += x[i], ny += y[i];
    		p = {nx,ny};
    		if(nx==0&&ny==0) {
    			// cout<<"I :"<<i<<" "<<sum[p]<<" "<<ans<<"\n";
    			ans += sum[p]+1;
    			sum[p]++;
    			// cout<<"ans:"<<ans<<" "<<sum[p]<<"\n";
    			continue;
    		}
    		ans += sum[p];
    		sum[p]++;
    	}
    	cout<<ans<<"\n";
    }
    return 0;
}