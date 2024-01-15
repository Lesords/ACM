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
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,one = 0,two = 0,three = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin>>tmp;
            if(tmp==1) one++;
            else if(tmp==2) two++;
            else three++;
        }
        cout<<one+three<<"\n";
    }
	return 0;
}
