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
    int t;
    cin>>t;
    while(t--) {
        ll l,r;
        cin>>l>>r;
        if(l*2<=r) cout<<l<<' '<<l*2<<endl;
        else cout<<"-1 -1"<<endl;
    }
	return 0;
}
