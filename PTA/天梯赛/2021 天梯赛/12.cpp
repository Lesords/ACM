#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<string>
#include<queue>
#include<utility>
#include<algorithm>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
vector<int> g[MAXN];
int sto[105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        int tmp,num;
        cin>>num;
        for(int j = 1;j <= num;j++) {
            cin>>tmp;
            g[i].push_back(tmp);
        }
    }
    int op,val,now = 1;
    for(int i = 1;i <= m;i++) {
        cin>>op>>val;
        if(op==0) {
            now = g[now][val-1];
        }
        else if(op==1) {
            sto[val] = now;
            cout<<now<<"\n";
        }
        else {
            now = sto[val];
        }
    }
    cout<<now<<"\n";
    return 0;
}
