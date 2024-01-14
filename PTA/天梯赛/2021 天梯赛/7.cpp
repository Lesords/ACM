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
const int MAXN = 2e4+5;
int a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int minn = a[1],cntmin = 1;
    int maxx = a[n],cntmax = 1;
    for(int i = 2;i <= n;i++) {
        if(a[i]==minn) cntmin++;
        else break;
    }
    for(int i = n-1;i >= 1;i--) {
        if(a[i]==maxx) cntmax++;
        else break;
    }
    cout<<minn<<" "<<cntmin<<"\n";
    cout<<maxx<<" "<<cntmax<<"\n";
    return 0;
}
