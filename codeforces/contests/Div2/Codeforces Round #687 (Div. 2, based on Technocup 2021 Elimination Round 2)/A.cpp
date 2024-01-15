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
        int n,m,r,c;
        cin>>n>>m>>r>>c;
        int val1 = max(abs(r-1)+abs(c-1),abs(r-1)+abs(c-m));
        int val2 = max(abs(r-n)+abs(c-m),abs(r-n)+abs(c-1));
        cout<<max(val1,val2)<<"\n";
    }
	return 0;
}
