#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 505;
int a[MAXN][MAXN],b[MAXN][MAXN];//a为原数组，b为临时操作数组
int n,m;
void output() {
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
}
void change(int x,int y,int r,int z) {//z为1逆时针，为0顺时针
    memset(b,0,sizeof(b));
    for(int i = 1;i <= r;i++) {//r代表需要操作的宽度
        //上 右 下 左 四个方向进行操作
        //上方    x-i,            y-i -> y+i
        //右方    x-i -> x+i      y+i
        //下方    x+i             y+i -> y-i
        //左方    x+i -> x-i      y-i
        if(z) for(int j = y-i,k = x-i;j <= y+i;j++,k++) b[x-i][j] = a[k][y+i];//上方
        else for(int j = y-i,k = x+i;j <= y+i;j++,k--) b[x-i][j] = a[k][y-i];
        if(z) for(int j = x-i,k = y+i;j <= x+i;j++,k--) b[j][y+i] = a[x+i][k];//右方
        else for(int j = x-i,k = y-i;j <= x+i;j++,k++) b[j][y+i] = a[x-i][k];
        if(z) for(int j = y+i,k = x+i;j >= y-i;j--,k--) b[x+i][j] = a[k][y-i];//下方
        else for(int j = y+i,k = x-i;j >= y-i;j--,k++) b[x+i][j] = a[k][y+i];
        if(z) for(int j = x+i,k = y-i;j >= x-i;j--,k++) b[j][y-i] = a[x-i][k];//左方
        else for(int j = x+i,k = y+i;j >= x-i;j--,k--) b[j][y-i] = a[x+i][k];
    }
    for(int i = 1;i <= n;i++)//更新修改后的数据
        for(int j = 1;j <= n;j++)
            if(b[i][j]) a[i][j] = b[i][j];//有修改才需要更新
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {//初始化原数组
        for(int j = 1;j <= n;j++) a[i][j] = (i-1)*n+j;//是n不是5!!!
    }
    int x,y,r,z;
    for(int i = 1;i <= m;i++) {
        cin>>x>>y>>r>>z;
        change(x,y,r,z);//修改操作
    }
    output();//输出操作
    return 0;
}
