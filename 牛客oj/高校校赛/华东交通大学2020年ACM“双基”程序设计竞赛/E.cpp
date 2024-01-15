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
string s[MAXN],a[MAXN];
int main() {
    int n,m;
    while(cin>>n>>m) {
        for(int i = 1;i <= n;i++) cin>>s[i],a[i] = s[i];
        sort(a+1,a+n+1);
        int flag = 0;
        for(int i = 1;i <= n;i++) {
            if(s[i]!=a[i]) {
                flag = 1;break;
            }
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
	return 0;
}
