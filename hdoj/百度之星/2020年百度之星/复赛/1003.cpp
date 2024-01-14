#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
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
const int MAXN = 1e5+5;
ll a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>l>>k;
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        ll maxx = 0,minn = 0;
        for(int i = 1;i <= n-k;i++) minn+=a[i];
        for(int i = k;i <= n;i++) maxx+=a[i];
        cout<<maxx<<' '<<minn<<endl;
    }
	return 0;
}
