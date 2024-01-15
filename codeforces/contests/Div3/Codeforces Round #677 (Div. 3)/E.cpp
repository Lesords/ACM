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
int main() {
    ll n;
    cin>>n;
    ll ans = 1;
    for(int i = 1;i < n;i++) ans *= i;
    cout<<ans/(n/2)<<endl;
	return 0;
}
