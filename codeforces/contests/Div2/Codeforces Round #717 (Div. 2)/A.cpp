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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k,tmp;
        cin>>n>>k;
        tmp = 0;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        for(int i = 1;i < n;i++) {
            if(k) {
                if(k>a[i]) {
                    k -= a[i];
                    tmp += a[i];
                    cout<<"0 ";
                }
                else {
                    cout<<a[i]-k<<" ";
                    tmp += k;
                    k = 0;
                }
            }
            else cout<<a[i]<<" ";
        }
        cout<<a[n]+tmp<<"\n";
    }
	return 0;
}
