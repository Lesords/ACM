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
int num[MAXN],del[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    while(t--) {
        memset(num,0,sizeof(num));
        memset(del,0,sizeof(del));
        int n,p,k,x,y;
        string tmp;
        cin>>n>>p>>k>>tmp>>x>>y;
        for(int i = 0;i < tmp.size();i++) {
            num[i%k] += tmp[i]=='0';
        }//以k为段，取模判断需要操作的次数
        for(int i = 0;i < p-1;i++) del[i%k] += tmp[i]=='0';
        int ans = (num[(p-1)%k]-del[(p-1)%k])*x;
        int pos = p-1;
        for(int i = 0;i < tmp.size()-p;i++) {
            del[pos%k] += tmp[pos]=='0';
            pos++;
            int tmp = (num[(i+p)%k]-del[(i+p)%k])*x+(i+1)*y;
            ans = min(ans,tmp);
        }
        cout<<ans<<"\n";
    }
	return 0;
}
