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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 105;
const int MOD = 1e9+7;
int id[MAXN],a[MAXN][MAXN],vis[MAXN];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,lan = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) {
            cin>>id[i],vis[i] = 1;
            if(id[i]==1) lan = i;
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                cin>>a[i][j];
            }
        }
        int die = a[lan][1];
        vis[die] = 0;//Ö»É±Ò»´Î£¡£¡£¡
        int num = n-1;
        if(vis[lan]==0) {
            cout<<"lieren\n";
            continue;
        }
        while(num>2) {
            for(int i = 1;i <= n;i++) {
                int tar = a[die][i];
                if(vis[tar]) {
                    num--;
                    die = tar;
                    vis[tar] = 0;
                    break;
                }
            }
            if(vis[lan]==0) break;
        }
        if(vis[lan]==1) cout<<"langren\n";
        else cout<<"lieren\n";
    }
	return 0;
}
