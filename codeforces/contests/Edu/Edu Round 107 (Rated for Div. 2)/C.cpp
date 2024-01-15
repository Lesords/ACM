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
const int MAXN = 3e5+5;
int a[MAXN*2];
void change(int pos) {
    int tmp = a[pos];
    for(int i = pos;i > 1;i--) {
        a[i] = a[i-1];
    }
    a[1] = tmp;
}
int main() {
    int n,q,t;
    cin>>n>>q;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= q;i++) {
        cin>>t;
        for(int j = 1;j <= n;j++) {
            if(a[j]==t) {
                cout<<j<<" ";
                change(j);
                break;
            }
        }
    }
	return 0;
}
