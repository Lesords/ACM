#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
struct node{
    ll v,num;
};
struct vertex{
    ll num,val;
    friend bool operator < (vertex a,vertex b) {
        ll a_val = a.num*(a.val-a.val/2);
        ll b_val = b.num*(b.val-b.val/2);
        return a_val < b_val;
    }
};
vector<node> g[MAXN];
ll val[MAXN],num[MAXN],cost[MAXN];
bool book[MAXN];
ll dfs(int dot) {
    if(g[dot].size()==1) return 1;
    ll ans = 0;
    node tmp;
    for(int i = 0;i < g[dot].size();i++) {
        tmp = g[dot][i];
        if(book[tmp.v]) continue;
        book[tmp.v] = 1;
        ans += num[tmp.num] = dfs(tmp.v);
    }
    return ans;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll v,u,n,s,sum = 0,ans = 0;
        cin>>n>>s;
        for(int i = 1;i < n;i++) {
            cin>>v>>u>>val[i]>>cost[i];
            book[i+1] = 0;
            g[v].push_back(node{u,i});
            g[u].push_back(node{v,i});
        }
        node tmp;
        book[1] = 1;
        for(int i = 0;i < g[1].size();i++) {
            tmp = g[1][i];
            book[tmp.v] = 1;
            num[tmp.num] = dfs(tmp.v);
        }
        priority_queue<vertex> one,two;
        for(int i = 1;i < n;i++) {
            sum += num[i]*val[i];
            if(cost[i]==1) one.push(vertex{num[i],val[i]});
            else two.push(vertex{num[i],val[i]});
        }
        vertex tri1,tri2,tri3;
        ll tnum1,tnum2,tnum3;
        while(sum>s) {
            tri1.num = tri2.num = tri3.num = 0;
            if(!one.empty()) tri1 = one.top(),one.pop();
            if(!one.empty()) tri2 = one.top(),one.pop();
            if(!two.empty()) tri3 = two.top(),two.pop();
            if(tri1.num&&(sum-tri1.num*(tri1.val-tri1.val/2))<=s) {
                ans++;break;
            }
            tnum1 = tri1.num*(tri1.val-tri1.val/2);
            tnum2 = max(tri1.num*(tri1.val/2-tri1.val/4),tri2.num*(tri2.val-tri2.val/2));
            tnum3 = tri3.num*(tri3.val-tri3.val/2);
            if(tnum1+tnum2>tnum3) {
                sum -= tnum1;
                tri1.val /= 2;
                ans++;
                if(tri3.num) two.push(tri3);
                one.push(tri1);
                one.push(tri2);
            }
            else {
                sum -= tnum3;
                ans += 2;
                tri3.val /= 2;
                if(tri1.num) one.push(tri1);
                if(tri2.num) one.push(tri2);
                two.push(tri3);
            }
        }
        cout<<ans<<endl;
        for(int i = 1;i <= n;i++) g[i].clear();
    }
	return 0;
}
