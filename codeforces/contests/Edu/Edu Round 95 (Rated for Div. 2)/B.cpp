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
int a[105],lock[105],ans[105];
bool cmp(int a,int b) {
    return a > b;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int cnt = 0;
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i <= n;i++) {
            cin>>lock[i];
            if(lock[i]==0) ans[++cnt] = a[i];
        }
        sort(ans+1,ans+cnt+1,cmp);
        cnt = 1;
        for(int i = 1;i <= n;i++) {
            if(lock[i]) cout<<a[i]<<' ';
            else cout<<ans[cnt++]<<' ';
        }
        cout<<endl;
    }
	return 0;
}
