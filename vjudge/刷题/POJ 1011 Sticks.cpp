#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 105;
int a[MAXN],vis[MAXN],n,num,sum,val;
bool cmp(int a,int b) {
    return a > b;
}
bool dfs(int cnt,int now,int index) {
    if(cnt==num) return 1;
    for(int i = index;i <= n;i++) {
        if(vis[i]||(a[i]==a[i-1]&&!vis[i-1])) continue;
        if(now+a[i]==val) {
            vis[i] = 1;
            if(dfs(cnt+1,0,0)) return 1;
            vis[i] = 0;
            return 0;
        }
        if(now+a[i]<val) {
            vis[i] = 1;
            if(dfs(cnt,now+a[i],i+1)) return 1;
            vis[i] = 0;
            if(!now) return 0;
        }
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin>>n&&n) {
        num = sum = 0;
        for(int i = 1;i <= n;i++) cin>>a[i],sum+=a[i];
        sort(a+1,a+n+1,cmp);
        int flag = 1;
        for(int i = a[1];i <= sum/2;i++) {
            if(sum%i) continue;
            num = sum/i,val = i;
            memset(vis,0,sizeof(vis));
            if(dfs(0,0,1)) {
                flag = 0;
                cout<<i<<"\n";break;
            }
        }
        if(flag) cout<<sum<<"\n";
    }
    return 0;
}
