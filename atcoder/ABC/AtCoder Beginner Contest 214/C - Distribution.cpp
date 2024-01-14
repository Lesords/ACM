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
struct node{
    int val, time;
    friend bool operator < (node a,node b) {
        return a.time > b.time;
    }
};
int s[MAXN], t[MAXN],vis[MAXN];
int main() {
    priority_queue<node> q;
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>s[i];
    }
    for(int i = 1;i <= n;i++) {
        cin>>t[i];
        q.push({i, t[i]});
    }
    while(!q.empty()) {
        node tmp = q.top();
        q.pop();
        if(vis[tmp.val]) continue;
        vis[tmp.val] = tmp.time;
        int toL = tmp.val+1;//Ö»ÄÜ+1£¡£¡£¡
        if(toL>n) toL -= n;
        if(vis[toL]==0) {
            q.push({toL, tmp.time+s[tmp.val]});
        }
    }
    for(int i = 1;i <= n;i++) {
        cout<<vis[i]<<"\n";
    }
	return 0;
}
