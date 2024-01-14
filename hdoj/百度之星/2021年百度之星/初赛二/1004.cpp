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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
ll a[MAXN],sum[MAXN];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ll n,m;
        scanf("%lld%lld", &n, &m);
        sum[0] = 0;
        int tmp_sum = 0;
        for(int i = 1;i <= n;i++) {
            scanf("%lld", &a[i]);
            sum[i] = sum[i-1]+a[i];
            tmp_sum += a[i];
            if(tmp_sum<0) tmp_sum = 0;
        }
        if(tmp_sum<0) {
            cout<<"-1\n";
            continue;
        }
        int cnt = 1;
        ll ans = tmp_sum;
        cnt += ceil(m*1.0/sum[n]);
        cout<<cnt<<"\n";
    }
	return 0;
}
