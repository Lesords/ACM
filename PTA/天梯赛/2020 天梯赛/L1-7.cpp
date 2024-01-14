#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e4+5;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;cin>>n>>m;
    ll start = 1<<n;
    int cnt = 0;
    for(int i = 1;i <= m;i++) {
        string tmp;
        cin>>tmp;
        ll pos = 1;
        for(int j = 0;j < (int) tmp.size();j++) {
            if(tmp[j]=='y') pos <<= 1;
            else pos = pos<<1|1;
        }
        cout<<pos-start+1<<"\n";
    }
    return 0;
}
