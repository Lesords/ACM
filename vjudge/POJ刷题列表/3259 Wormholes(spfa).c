#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 505;
struct node{
    int dot,val;
};
vector<node> g[MAXN];
int n,m,w,dis[MAXN],num[MAXN];
int main() {
    int F;
    cin>>F:
    while(F--) {
        cin>>n>>m>>w;
        int s,e,t;
        for(int i = 1;i <= m;i++) {
            cin>>s>>e>>t;
            g[s].push_back(node{e,t});
            g[e].push_back(node{s,t});
        }
        for(int i = 1;i <= w;i++) {
            cin>>s>>e>>t;
            g[s].push_back(node{e,-t});
        }
        if(spfa(1)) cout<<"YES\n";
        else cout<<"NO\n";
        for(int i = 1;i <= n;i++) g[i].clear();
    }
    return 0;
}
