#include<iostream>// ?
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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
ll ans,n,vis[50],a[50];
void dfs(int pos,int last) {
    if(pos==n+1) {
        int flag = 0;
        for(int i = 1;i <= 6;i++) if(vis[i]) ++flag;
        if(flag>=3) ans++;
//        if(flag>=3) {
//            for(int i = 1;i <= n;i++) cout<<vis[i]<<" ";
//        cout<<endl;
//            for(int i = 1;i <= n;i++) cout<<a[i]<<" ";
//            cout<<"\n";
//        }
        return;
    }
    for(int i = 1;i <= 6;i++) {
        if(last!=-1&&abs(last-i)>=5) continue;
        vis[i]++;
        a[pos] = i;
        dfs(pos+1,i);
        vis[i]--;
    }
}
int main() {
//    while(cin>>n) {
//        ans = 0;
//        memset(vis,0,sizeof(vis));
//        dfs(1,-1);
//        cout<<ans<<"\n";
//    }
    for(int i = 3;i <= 25;i++) {
        n = i;
        ans = 0;
        memset(vis,0,sizeof(vis));
        dfs(1,-1);
        cout<<ans<<"\n";
    }
	return 0;
}
/*
104
904
5880
35080
203224
1165224
6656760
37980360
216600344
1235066344
*/
