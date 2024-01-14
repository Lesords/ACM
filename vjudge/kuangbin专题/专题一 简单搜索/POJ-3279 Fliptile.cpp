#include<iostream>//ac  状态压缩
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：状态压缩，先枚举第一行的状态
//然后接下来的每一行的状态都由上一行决定，最后判断最后一行是否满足条件即可
//注意：需要先记录最小的翻转次数，然后才是字典序

int n,m,a[20][20],op[20][20],b[20][20],ans[20][20];//ans保存最后的操作
//z为原数组，b为中间存储数组，op为当前操作
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};
void change(int x,int y) {//翻转当前位置及周围四个连接位置的值
    b[x][y] ^= 1;// ^1即为取反
    for(int i = 0;i < 4;i++) {
        int tx = x+nextt[i][0];
        int ty = y+nextt[i][1];
        if(tx<1||tx>n||ty<1||ty>m) continue;//跳过越界
        b[tx][ty] ^= 1;
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin>>a[i][j];
        }
    }
    int num = INF;//num记录最少的翻转次数
    for(int i = 0;i < (1<<m);i++) {//枚举所有状态（状态压缩）
        int cnt = 0;//cnt记录当前翻转的次数
        for(int j = 1;j <= n;j++)//初始化
            for(int k = 1;k <= m;k++) b[j][k] = a[j][k],op[j][k] = 0;
        for(int j = 0;j < m;j++) {//根据字典序，右边为低位！！！
            op[1][m-j] = (i>>j)&1;//判断第j位是否为1（令0位初始位）
            if(op[1][m-j]) change(1,m-j),cnt++;
        }
        for(int j = 2;j <= n;j++) {//从第二行开始判断，要判断到最后一行！！！
            for(int k = 1;k <= m;k++) {//判断上一行的值
                if(b[j-1][k]) op[j][k] = 1,change(j,k),cnt++;
            }//值为1则需要翻转
        }
        int ff = 0;
        for(int j = 1;j <= m;j++) if(b[n][j]) {//判断最后一行是否存在1
            ff = 1;break;//存在则不满足条件
        }
        if(ff) continue;
        if(cnt<num) {//更新最小值
            num = cnt;
            for(int j = 1;j <= n;j++)//更新操作数组
                for(int k = 1;k <= m;k++) ans[j][k] = op[j][k];
        }
    }
    if(num==INF) cout<<"IMPOSSIBLE\n";//INF即为无解
    else for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(j!=1) cout<<" ";
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
/*
无解的样例：
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 1
*/
