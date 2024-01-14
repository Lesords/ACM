#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 110;
int f[MAXN],v[MAXN][MAXN], w[MAXN][MAXN],c[MAXN];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>c[i];
        for(int j = 1;j <= c[i];j++) cin>>v[i][j]>>w[i][j];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = m;j >= 0;j--) {
            for(int k = 1;k <= c[i];k++) {
                if(j>=v[i][k]) f[j] = max(f[j], f[j-v[i][k]]+w[i][k]);
            }
        }
    }
//    for(int i = 1;i <= n;i++) {
//        int s;
//        cin>>s;
//        for(int j = 1;j <= s;j++) {
//            int v,w;
//            cin>>v>>w;
//            for(int k = m;k >= v;k--) {
//                if(f[i][k]) f[i][k] = max(f[i][k], f[i-1][k-v] + w);
//                else {
//                    f[i][k] = max(f[i-1][k], f[i-1][k-v]+w);
//                }
//            }
//        }
//    }
//    cout<<f[n][m];
    cout<<f[m];
    return 0;
}
