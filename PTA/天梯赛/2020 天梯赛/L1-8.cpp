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
int money[] = {10000,36,720,360,80,252,108,72,54,180,72,
180,119,36,306,1080,144,1800,3600};
int matrix[5][5],vis[10];
int see[5][5];
int main() {
    int sx,sy;
    for(int i = 1;i <= 3;i++) {
        for(int j = 1;j <= 3;j++) {
            cin>>matrix[i][j];
            if(matrix[i][j]==0) sx = i,sy = j,see[i][j] = 1;
            vis[matrix[i][j]] = 1;
        }
    }
    for(int i = 1;i <= 9;i++) {
        if(vis[i]) continue;
        matrix[sx][sy] = i;
        break;
    }
    for(int i = 1;i <= 3;i++) {
        int a,b;
        cin>>a>>b;
        cout<<matrix[a][b]<<"\n";
        see[a][b] = 1;
    }
    int op;cin>>op;
    int ans = 0;
    if(op==1) {
        for(int i = 1;i <= 3;i++) ans += matrix[1][i];
    }
    else if(op==2) {
        for(int i = 1;i <= 3;i++) ans += matrix[2][i];
    }
    else if(op==3) {
        for(int i = 1;i <= 3;i++) ans += matrix[3][i];
    }
    else if(op==4) {
        for(int i = 1;i <= 3;i++) ans += matrix[i][1];
    }
    else if(op==5) {
        for(int i = 1;i <= 3;i++) ans += matrix[i][2];
    }
    else if(op==6) {
        for(int i = 1;i <= 3;i++) ans += matrix[i][3];
    }
    else if(op==7) {
        for(int i = 1;i <= 3;i++) ans += matrix[i][i];
    }
    else {
        int pos = 1;
        for(int i = 3;i >= 1;i--) ans += matrix[pos++][i];
    }
    cout<<money[ans-6];
    return 0;
}
