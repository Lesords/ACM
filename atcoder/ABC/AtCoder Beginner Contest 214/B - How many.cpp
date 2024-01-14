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
int main() {
    int s,t;
    cin>>s>>t;
    int ans = 0;
    for(int i = 0;i <= 100;i++) {
        for(int j = 0;j <= 100;j++) {
            for(int k = 0;k <= 100;k++) {
                if(i+j+k>s) continue;
                if(i*j*k>t) continue;
                ans++;
            }
        }
    }
    cout<<ans;
	return 0;
}
