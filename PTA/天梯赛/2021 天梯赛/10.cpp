#include<iostream>//22
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<string>
#include<queue>
#include<utility>
#include<algorithm>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 1e4+5;
vector<int> g[MAXN];
vector<int> ans,tmp;
int in[MAXN],maxx;
bool judge() {
    if(tmp.size()>ans.size()) {
        return true;
    }
    if(tmp.size()==ans.size()) {
        for(int i = 0;i < tmp.size();i++) {
            if(tmp[i]<ans[i]) return true;
        }
    }
    return false;
}
void dfs(int pos) {
    if(g[pos].empty()) {
        if(judge()) {
            ans = tmp;
        }
        return ;
    }
    for(int i = 0;i < g[pos].size();i++) {
        int now = g[pos][i];
        tmp.push_back(now);
        dfs(now);
        tmp.pop_back();
    }
}
int main() {
    int n;
    cin>>n;
    for(int i = 0;i < n;i++) {
        int num,tmp;
        cin>>num;
        for(int j = 1;j <= num;j++) {
            cin>>tmp;
            g[i].push_back(tmp);
            in[tmp]++;
        }
    }
    int rt = 0;
    for(int i = 0;i < n;i++) {
        if(in[i]==0) {
            rt = i;break;
        }
    }
    tmp.push_back(rt);
    dfs(rt);
    cout<<ans.size()<<"\n";
    for(int i = 0;i < ans.size();i++) {
        if(i!=0) cout<<" ";
        cout<<ans[i];
    }
    return 0;
}
