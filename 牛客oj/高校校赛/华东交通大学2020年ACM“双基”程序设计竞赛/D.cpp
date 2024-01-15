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
int a[5];
int main() {
    while(cin>>a[1]) {
        for(int i = 2;i <= 3;i++) cin>>a[i];
        sort(a+1,a+4);
        int tmp1 = a[1]*a[1]+a[2]*a[2];
        int tmp2 = a[3]*a[3];
        if(tmp1==tmp2) cout<<"YES\n";
        else cout<<"NO\n";
    }
	return 0;
}
