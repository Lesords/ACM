#include<iostream>
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
const int MAXN = 5e5+5;
int a[MAXN],b[MAXN],ans[MAXN];
int main() {
    fast;
    int n,m,x;
    cin>>n>>m>>x;
    for(int i = 1;i <= n;i++) cin>>a[i];
    int now = 0,ans = 0,last = 0;
    for(int i = 1;i <= m;i++) {
        int op,h,t;
        cin>>op;
        if(op==1) {
            cin>>h>>t;
            for(int j = 1;j <= min(n,h);j++) b[j] += a[i];
        }
    }
	return 0;
}
