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
const int MAXN = 1e3+5;
const int MOD = 1e9+7;
struct node{
    int x,y;
};
int dis[2][MAXN];
vector<node> ans;
int getf(int pos, int st) {
    return dis[st][pos]==pos?pos:dis[st][pos] = getf(dis[st][pos], st);
}
int Merge(int a,int b, int st) {
    a = getf(a, st);
    b = getf(b, st);
    if(a>b) swap(a,b);
    if(a!=b) {
        dis[st][b] = a;
    }
}
int main() {
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
    int num = 0,ok = 0;
    for(int i = 1;i <= n;i++) {//暴力判断所有点对是否可以合并，若可以则直接合并
        for(int j = i+1;j <= n;j++) {
            int ai = getf(i, 0);
            int aj = getf(j, 0);
            int bi = getf(i, 1);
            int bj = getf(j, 1);
            if(ai!=aj&&bi!=bj) {
                num++;
                Merge(ai, aj, 0);//参数错了！！！
                Merge(bi, bj, 1);
                ans.push_back({i,j});
            }
            if(num+m1==n-1||num+m2==n-1) {
                ok = 1;break;
            }
        }
        if(ok) break;
    }
    cout<<num<<"\n";
    for(int i = 0;i < ans.size();i++) {
        cout<<ans[i].x<<" "<<ans[i].y<<"\n";
    }
	return 0;
}
