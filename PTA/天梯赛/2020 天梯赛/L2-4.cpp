#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
#define INF 0x7f7f7f7f
using namespace std;
const int MAXN = 1e4+5;
ll g[205][205],path[205];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 0;i <= n;i++) {//初始化，记得包括起点0！！！
        for(int j = 0;j <= n;j++) {
            if(i==j) g[i][j] = 0;
            else g[i][j] = INF;
        }
    }
    for(int i = 1;i <= m;i++) {
        ll a,b,c;
        cin>>a>>b>>c;
        g[a][b] = g[b][a] = c;
    }
    int k;cin>>k;
    ll ans = 0,index = 0,val = INF;
    for(int i = 1;i <= k;i++) {//判断k个策略
        int tt,flag = 0;cin>>tt;
        ll num = 0;
        set<int> st;
        st.clear();
        for(int j = 1;j <= tt;j++) {
            cin>>path[j];
            if(st.count(path[j])) flag = 1;//重复经过网红点
            if(flag) continue;
            st.insert(path[j]);
            ll tmp;//tmp为到达当前点的路段费用
            if(j==1) tmp = g[0][path[j]];
            else tmp = g[path[j-1]][path[j]];
            if(tmp==INF) flag = 1;//特判是否为可连接路！！！
            else num += tmp;
        }
        if(flag||g[path[tt]][0]==INF) continue;
        num += g[path[tt]][0];
        if(st.size()==n) {//要经过n个网红点
            ans++;
            if(num<val) {
                val = num;
                index = i;
            }
        }
    }
    cout<<ans<<"\n";
    cout<<index<<" "<<val<<'\n';
    return 0;
}
/*
6 13
0 5 2
6 2 2
6 0 1
3 4 2
1 5 2
2 5 1
3 1 1
4 1 2
1 6 1
6 3 2
1 2 1
4 5 3
2 0 2
7
6 5 1 4 3 6 2
6 5 2 1 6 3 4
8 6 2 1 6 3 4 5 2
3 2 1 5
6 6 1 3 4 5 2
7 6 2 1 3 4 5 2
6 5 2 1 4 3 6
*/
