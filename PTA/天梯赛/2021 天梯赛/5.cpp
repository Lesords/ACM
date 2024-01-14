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
int a[55];
int main() {
    for(int i = 0;i <= 23;i++) {
        cin>>a[i];
    }
    int val;
    while(cin>>val) {
        if(val<0||val>23) break;
        cout<<a[val]<<" ";
        if(a[val]>50) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
