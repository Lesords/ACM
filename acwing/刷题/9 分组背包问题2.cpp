#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 110;
int f[MAXN][MAXN];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        int s;
        cin>>s;
        for(int j = 1;j <= s;j++) {
            int v,w;
            cin>>v>>w;
            for(int k = m;k >= 0;k--) {
                if(f[i][k]) {
                    if(k>=v) f[i][k] = max(f[i][k], f[i-1][k-v] + w);
                }
                else {
                    f[i][k] = f[i-1][k];
                    if(k>=v) f[i][k] = max(f[i][k], f[i-1][k-v] + w);
                }
            }
        }
    }
    cout<<f[n][m];
    return 0;
}
