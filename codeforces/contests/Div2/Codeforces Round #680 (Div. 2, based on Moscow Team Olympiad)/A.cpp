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
int a[MAXN],b[MAXN];
bool cmp(int a,int b) {
    return a > b;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,x;
        cin>>n>>x;
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        for(int i = 1;i <= n;i++) cin>>b[i];
        sort(b+1,b+n+1,cmp);
        int flag = 1;
        for(int i = 1;i <= n;i++) {
            if(a[i]+b[i]>x) {
                flag = 0;break;
            }
        }
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
	return 0;
}
