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
const int MAXN = 5e4+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        int flag = 0;
        for(int i = 2;i <= n;i++) {
            if(a[i]>=a[i-1]) flag = 1;
        }
        if(!flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
	return 0;
}
