#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int MAXN = 1e4+5;
int main() {
    ll n,k,m;
    cin>>n>>k>>m;
    cout<<max(0ll,(n-k*m));
    return 0;
}
