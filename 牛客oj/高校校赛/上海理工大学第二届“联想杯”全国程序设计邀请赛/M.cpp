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

//题解：直接模拟

const int MAXN = 35;
const int MOD = 1e9+7;
struct node{
    int x,y,z;
};
vector<node> g[MAXN];
set<char> st;
char s[MAXN][MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];
int n,m,h;
int idx(char ch) {
    return ch - 'A';
}
bool judge() {
    for(int i = 1;i <= h;i++) {
        for(int j = 1;j <= n;j++) {
            for(int k = 1;k <= m;k++) {
                if(vis[i][j][k]==0) return true;
            }
        }
    }
    return false;
}
bool work(int id) {
    if(g[id].size()==0) return false;
    for(int i = 0;i < g[id].size();i++) {
        node tmp = g[id][i];
        if(tmp.z>1) {
             int tid = idx(s[tmp.z-1][tmp.x][tmp.y]);
             if(tid==id) continue;
        }
        if(tmp.z!=1&&vis[tmp.z-1][tmp.x][tmp.y]==0) return false;
    }
    for(int i = 0;i < g[id].size();i++) {
        node tmp = g[id][i];
        vis[tmp.z][tmp.x][tmp.y] = 1;
    }
    return true;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>m>>h;
        for(int i = 0;i < 26;i++) g[i].clear();
        for(int i = h; i >= 1;i--) {
            for(int j = 1;j <= n;j++) {
                for(int k = 1;k <= m;k++) {
                    cin>>s[i][j][k];
                    vis[i][j][k] = 0;
                    g[idx(s[i][j][k])].push_back({j,k,i});
                }
            }
        }
        int flag = 0;
        string ans = "";
        st.clear();
        while(judge()) {
            int mark = 0;
            for(char c = 'Z';c >= 'A';c--) {
                if(st.find(c)!=st.end()) continue;
                if(work(idx(c))) {
                    ans += c;
                    st.insert(c);
                    mark = 1;
                    break;
                }
            }
            if(!mark) {
                flag = 1;break;
            }
        }
        if(flag) cout<<"-1\n";
        else cout<<ans<<"\n";
    }
	return 0;
}
/*
1
2 2 2
BA
BB
AA
BA
*/
