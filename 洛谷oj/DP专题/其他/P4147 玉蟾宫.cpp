#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：悬线法
//分别记录向左、向右、向上可以扩张的大小
//边界位置的值需要判断是否为F，是则为1否则为0

const int MAXN = 1e3+5;
char a[MAXN][MAXN];
int l[MAXN][MAXN],r[MAXN][MAXN],u[MAXN][MAXN];
//l记录向左，r记录向右，u记录向上
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin>>a[i][j];
    }
    //计算向左扩张的大小
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(j==1) l[i][j] = a[i][j]=='F';
            else {
                if(a[i][j]=='F') l[i][j] = l[i][j-1]+1;
            }
        }
    }
    //计算向右扩张的大小
    for(int i = 1;i <= n;i++) {
        for(int j = m;j >= 1;j--) {
            if(j==m) r[i][j] = a[i][j]=='F';
            else {
                if(a[i][j]=='F') r[i][j] = r[i][j+1]+1;
            }
        }
    }
    int ans = 0;
    //计算向上扩张的大小
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(i==1) u[i][j] = a[i][j]=='F';
            else {
                if(a[i][j]=='F') u[i][j] = u[i-1][j]+1;
            }
        }
    }
    //注意转移的时候变量没写错了！！！
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(a[i][j]=='F') {//当前为F才需要计算！！！
                if(i>1&&a[i-1][j]=='F') {//上一行为F才需要转移！！！
                    l[i][j] = min(l[i][j], l[i-1][j]);
                    r[i][j] = min(r[i][j], r[i-1][j]);
                }
                //计算当前悬线左右移动，可以组成的最大矩形
                ans = max(ans, u[i][j]*(l[i][j]+r[i][j]-1));
            }
        }
    }
    cout<<ans*3<<"\n";
    return 0;
}
