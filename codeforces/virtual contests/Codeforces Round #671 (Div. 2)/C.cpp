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
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,x,flag = 0,sum = 0,cnt = 0;
        cin>>n>>x;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            if(a[i]!=x) flag = 1;
            if(a[i]==x) cnt = 1;
            sum += x-a[i];
        }
        if(flag==0) {
            cout<<"0\n";continue;
        }
        if(sum==0||cnt) cout<<"1\n";
        else cout<<"2\n";

    }
	return 0;
}
