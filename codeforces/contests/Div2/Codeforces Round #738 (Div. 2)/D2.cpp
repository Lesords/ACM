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
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
struct node{
    int x,y;
};
int dis[2][MAXN],num[MAXN];
vector<node> ans;
int getf(int pos, int st) {
    return dis[st][pos]=dis[st][pos]==pos?pos:getf(dis[st][pos], st);
}
void Merge(int a,int b, int st) {
    a = getf(a, st);
    b = getf(b, st);
    if(a>b) swap(a,b);
    if(a!=b) {
        dis[st][b] = a;
    }
}
bool Equal(int a,int b,int st) {
    return getf(a, st) == getf(b, st);
}
int main() {
    fast;
    int n,m1,m2;
    cin>>n>>m1>>m2;
    for(int i = 1;i <= n;i++) dis[0][i] = dis[1][i] = i;
    for(int i = 1;i <= m1;i++) {
        int u,v;
        cin>>u>>v;
        Merge(u, v, 0);
    }
    for(int i = 1;i <= m2;i++) {
        int u,v;
        cin>>u>>v;
        Merge(u, v, 1);
    }
    stack<int> one, zero;
    //zero为第一个森林中不与1联通的点
    //one为第二个森林中不与1联通的点
    for(int i = 2;i <= n;i++) {
        if(Equal(i, 1, 0)==0&&Equal(i, 1, 1)==0) {
            ans.push_back({1, i});
            Merge(i, 1, 0);
            Merge(i, 1, 1);
        }
        if(Equal(i, 1, 0)==0) zero.push(i);
        if(Equal(i, 1, 1)==0) one.push(i);
    }
    while(!zero.empty()&&!one.empty()) {
        if(!zero.empty()&&Equal(1, zero.top(), 0)) {
            zero.pop();continue;
        }
        if(!one.empty()&&Equal(1, one.top(), 1)) {
            one.pop();continue;
        }
        int tzero = zero.top();
        zero.pop();
        int tone = one.top();
        one.pop();
        ans.push_back({tzero, tone});
        Merge(tzero, tone, 0);
        Merge(tzero, tone, 1);
    }
    cout<<ans.size()<<"\n";
    for(int i = 0;i < ans.size();i++) {
        cout<<ans[i].x<<" "<<ans[i].y<<"\n";
    }
	return 0;
}
