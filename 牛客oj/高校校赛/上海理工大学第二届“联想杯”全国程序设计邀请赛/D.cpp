#include<iostream>
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
const int MAXN = 505;
const int MOD = 1e9+7;
struct node{
    int u,v,w;
    friend bool operator < (node a,node b) {
        return a.w > b.w;
    }
};
vector<node> g;
vector<int> ver;
set<int> st;
int dis[MAXN],val[MAXN][MAXN];
int getf(int pos) {
    return pos==dis[pos]?pos:dis[pos]=getf(dis[pos]);
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        dis[i] = i;
        for(int j = 1;j <= n;j++) {
            int tmp;
            cin>>tmp;
            val[i][j] = tmp;
            if(i<j) {
                g.push_back({i,j,tmp});
            }
        }
    }
    sort(g.begin(),g.end());
    ll ans = 0;
    for(int i = 0;i < g.size();i++) {
        node tmp = g[i];
        ll num = 0;
        if(getf(tmp.u)!=getf(tmp.v)) {
            dis[getf(tmp.v)] = getf(tmp.u);
            if(st.find(tmp.v)==st.end()) ver.push_back(tmp.v),st.insert(tmp.v);
            for(int j = 0;j < ver.size();j++) {
                for(int k = 0;k < ver.size();k++) {
                    num += val[ver[j]][ver[k]];
                }
            }
            for(int j = 1;j <= n;j++) {
                if(st.find(j)!=st.end()) continue;
                for(int k = 1;k <= n;k++) {
                    if(st.find(k)!=st.end()) continue;
                    num += val[j][k];
                }
            }
            ans = max(ans, num);
            if(ver.size()==n-1) break;
            if(st.find(tmp.u)==st.end()) ver.push_back(tmp.u),st.insert(tmp.u);
            num = 0;
            for(int j = 0;j < ver.size();j++) {
                for(int k = 0;k < ver.size();k++) {
                    num += val[ver[j]][ver[k]];
                }
            }
            for(int j = 1;j <= n;j++) {
                if(st.find(j)!=st.end()) continue;
                for(int k = 1;k <= n;k++) {
                    if(st.find(k)!=st.end()) continue;
                    num += val[j][k];
                }
            }
            ans = max(ans, num);
            if(ver.size()==n-1) break;
        }
    }
    cout<<ans;
	return 0;
}
