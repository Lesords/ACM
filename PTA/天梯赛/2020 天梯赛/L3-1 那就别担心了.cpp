#include<iostream>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 505;
vector<int> g[MAXN];
int in[MAXN],out[MAXN],ans,dp[MAXN];
void dfs(int pos,int ed) {
    if(pos==ed) {
        return;
    }
    for(int i = 0;i < g[pos].size();i++) {
        int now = g[pos][i];
        dp[now] += dp[pos];
        dfs(now,ed);
    }
}
int main() {
    int n,m,st,ed;
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        in[y]++,out[x]++;
    }
    int num = 0;
    for(int i = 1;i <= n;i++) {
        if(out[i]==0) {
            num++;
        }
    }
    cin>>st>>ed;
    dp[st] = 1;
    dfs(st,ed);
    cout<<dp[ed]<<" "<<(num>1?"No":"Yes");
    return 0;
}
