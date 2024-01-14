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
int book[105],a[105];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int flag = 0,last = 0;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        last = a[1];
        for(int i = 2;i <= n;i++) {
            if(a[i]==last) {
                flag = 1; break;
            }
            else last = a[i];
        }
        if(flag) {
            cout<<"NO\n";
        }
        else cout<<"YES\n";
    }
	return 0;
}
