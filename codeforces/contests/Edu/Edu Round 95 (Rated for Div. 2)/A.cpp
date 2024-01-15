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
        ll x,y,k;
        cin>>x>>y>>k;
        ll tmp = k*y+k-1;
        if(tmp%(x-1)==0) cout<<tmp/(x-1)+k<<endl;
        else cout<<tmp/(x-1)+1+k<<endl;
    }
	return 0;
}
