#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 1e7+6;
int tree[MAXN],a[1005],vis[MAXN];
int solve(int n) {
    int i = 1,high = 1;
    while(n>i) {
        high++;
        i = i<<1|1;
    }
    return high-1;
}
int main() {
    int n,maxx = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    tree[1] = a[1];
    vis[1] = 1;
    for(int i = 2;i <= n;i++) {
        int pos = 1;
        while(tree[pos]) {
            if(a[i]<=tree[pos]) {
                pos = pos<<1;
            }
            else pos = pos<<1|1;
        }
        tree[pos] = a[i];
        vis[pos] = 1;
        maxx = max(maxx,pos);
    }
    int ans = 0;
    int high = solve(maxx);
    for(int i = maxx;i >= 1;i--) {
        if(vis[i]==0) continue;
        if(high-solve(i)<=1) ans++;
        else break;
    }
    cout<<ans<<endl;
    return 0;
}
