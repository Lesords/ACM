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
#define INF 1e18
#define fi first
#define se second
using namespace std;
const int MAXN = 35;
ll a[MAXN] = {0,1},num[MAXN];
int main() {
    for(int i = 2;i < MAXN;i++) {
        a[i] = a[i-1]*2+1;
    }
    for(int i = 1;i < MAXN;i++) {
        num[i] = a[i]*((a[i]+1)/2) + num[i-1];
    }
    int t;
    cin>>t;
    while(t--) {
        ll x;
        cin>>x;
        int index = 1;
        for(int i = 1;i < MAXN;i++) {
            if(num[i]<=x) index = i;
            else break;
        }
        cout<<index<<endl;
    }
	return 0;
}
