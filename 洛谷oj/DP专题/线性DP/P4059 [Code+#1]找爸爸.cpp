#include<iostream>//ac
#include<cstring>
#include<string>
#include<map>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：线性dp
//由于需要匹配两个DNA序列

const int MAXN = 3003;
map<char,int> idx;
char c[MAXN];
int a[MAXN],b[MAXN];
int n,m,val[5][5],A,B;
int f[MAXN][MAXN][3];
int main() {
    idx['A'] = 1;
    idx['T'] = 2;
    idx['G'] = 3;
    idx['C'] = 4;
    cin>>c+1;
    n = strlen(c+1);
    for(int i = 1;i <= n;i++) {
        a[i] = idx[c[i]];
    }
    cin>>c+1;
    m = strlen(c+1);
    for(int i = 1;i <= m;i++) {
        b[i] = idx[c[i]];
    }
    for(int i = 1;i <= 4;i++) {
        for(int j = 1;j <= 4;j++) cin>>val[i][j];
    }
    cin>>A>>B;
    // memset(f,0xcf,sizeof(f));//赋值为-808464433
    for(int i = 0;i <= n;i++)
        for(int j = 0;j <= m;j++) f[i][j][0] = f[i][j][1] = f[i][j][2] = -INF;
    f[0][0][0] = 0,f[0][1][1] = f[1][0][2] = -A;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            f[i][j][0] = max(max(f[i-1][j-1][1], f[i-1][j-1][2]), f[i-1][j-1][0]) + val[a[i]][b[j]];
            f[i][j][1] = max(max(f[i][j-1][0]-A, f[i][j-1][1]-B), f[i][j-1][2]-A);
            f[i][j][2] = max(max(f[i-1][j][0]-A, f[i-1][j][1]-A), f[i-1][j][2]-B);
        }
    }
    cout<<max(max(f[n][m][1],f[n][m][2]), f[n][m][0]);
    return 0;
}
