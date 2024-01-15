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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 105;
int a[MAXN];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        memset(a,0,sizeof(a));
        if(k<=((n-1)/2)) {
            int cnt = n;
            for(int i = 2;i <= n;i+=2) {
                if(k==0) {
                    break;
                }
                a[i] = cnt--;
                k--;
            }
            for(int i = 1;i <= n;i++) {
                if(a[i]) continue;
                a[i] = cnt--;
            }
            for(int i = 1;i <= n;i++) {
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
        else cout<<"-1\n";
    }
	return 0;
}
