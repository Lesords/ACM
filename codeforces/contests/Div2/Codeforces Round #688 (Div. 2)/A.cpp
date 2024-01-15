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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int a[105],b[105],vis[105];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m,ans = 0;
        memset(vis,0,sizeof(vis));
        cin>>n>>m;
        for(int i = 1;i <= n;i++) cin>>a[i],vis[a[i]]++;//标记行
        for(int i = 1;i <= m;i++) {
            cin>>b[i];
            if(vis[b[i]]) ans++;//判断行对应数是否出现过
        }
        cout<<ans<<"\n";
    }
	return 0;
}
