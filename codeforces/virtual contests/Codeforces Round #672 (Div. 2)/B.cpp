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
int a[MAXN],num[50];
void solve(int n) {
    int cnt = 0;
    while(n) {
        cnt++;n>>=1;
    }
    num[cnt]++;
}
int main() {
    int t;cin>>t;
    while(t--) {
        memset(num,0,sizeof(num));
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            solve(a[i]);
        }
        ll ans = 0;
        for(int i = 1;i <= 32;i++) ans += num[i]*1ll*(num[i]-1)/2;
        cout<<ans<<endl;
    }
	return 0;
}
