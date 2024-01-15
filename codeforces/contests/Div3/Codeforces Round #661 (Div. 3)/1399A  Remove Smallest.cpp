#include<iostream>//ac
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
const int MAXN = 55;
int a[MAXN];
int main() {
    int t,n;
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+n+1);
        int flag = 0;
        for(int i = 2;i <= n;i++) {
            if(a[i]-a[i-1]>1) {
                flag = 1;break;
            }
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
	return 0;
}
