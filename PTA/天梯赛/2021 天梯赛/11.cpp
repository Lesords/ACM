#include<iostream>//17·Ö
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
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN][105];
vector<int> ans[MAXN];
map<int,pii> num;
int main() {
    int n,m,cnt = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin>>a[i][j];
        }
        num[a[i][1]].fi++;
        num[a[i][1]].se = i;
    }
    int minn = INF,maxx = 0;
    for(auto val:num) {
        pii p = val.se;
        ans[p.fi].push_back(p.se);
        cnt++;
        minn = min(minn, p.fi);
        maxx = max(maxx, p.fi);
    }
    cout<<cnt<<"\n";
    for(int i = maxx;i >= minn;i--) {
        if(ans[i].empty()) continue;
        for(int j = 0;j < ans[i].size();j++) {
            cout<<i;
            int now = ans[i][j];
            for(int k = 1;k <= m;k++) {
                cout<<" "<<a[now][k];
            }
            cout<<"\n";
        }
    }
    return 0;
}
