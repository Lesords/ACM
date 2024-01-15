#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[105][105],book[105][105],r,c;
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};//四个方向

//题解：dfs遍历所有点为起点，记忆化可缩短运行时间

int dfs(int x,int y) {
    int tmp = 0;
    if(book[x][y]) return book[x][y];//已经记录过的，直接返回
    for(int i = 0;i < 4;i++) {
        int tx = x+nextt[i][0];//注意x和y！！！
        int ty = y+nextt[i][1];
        if(tx<1||tx>r||ty<1||ty>c) continue;//越界
        if(a[tx][ty]<a[x][y]) {//如果目的点小于当前点
            tmp = max(tmp,dfs(tx,ty));//取较大值
        }
    }
    return book[x][y] = 1+tmp;//记忆化，结果为当前点(1)+tmp
}
int main() {
    int ans = 0;
    cin>>r>>c;
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= c;j++) cin>>a[i][j];
    }
    for(int i = 1;i <= r;i++) {//所有的点都dfs
        for(int j = 1;j <= c;j++) {
            ans = max(ans,dfs(i,j));//取较大值
        }
    }
    cout<<ans<<endl;
    return 0;
}
