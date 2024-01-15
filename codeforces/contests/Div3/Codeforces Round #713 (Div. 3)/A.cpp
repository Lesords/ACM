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
int a[MAXN];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,ans = 0;
        map<int,int> num,one;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            num[a[i]]++;
            if(num[a[i]]==1) {
                one[a[i]] = i;
            }
        }
        for(auto val:num) {
            if(val.second==1) {
                cout<<one[val.first]<<"\n";
                break;
            }
        }
    }
	return 0;
}
