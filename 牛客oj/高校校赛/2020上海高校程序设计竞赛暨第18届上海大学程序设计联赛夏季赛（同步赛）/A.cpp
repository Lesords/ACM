#include<iostream>//wa
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
int main() {
    ll t,n,k;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        if(n%k) cout<<"-1 -1 -1\n";
        else {
            ll tmp = n/k;
            if(tmp/2<=3) cout<<"-1 -1 -1\n";
            else {
                cout<<tmp/2*k<<' '<<(tmp-tmp/2-2)*k<<' '<<2*k<<endl;
            }
        }
    }
	return 0;
}
