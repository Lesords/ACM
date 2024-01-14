#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//题解：dfs取所有路径数，特判最后一个点能否到达起点

int a[25],vis[25],cnt,g[25][25],m;
void dfs(int dot,int pos) {//dot为当前点，pos为当前位置
    if(pos==20) {//到达最后 一个点时
        if(g[dot][m]==0) return;//特判能否到达起点！！！
        cout<<++cnt<<":  ";
        for(int i = 1;i <= pos;i++) {
            cout<<a[i]<<" ";
        }
        cout<<m<<"\n";//多输出起点
    }
    for(int i = 1;i <= 20;i++) {
        if(i==dot) continue;//跳过当前点
        if(vis[i]||g[dot][i]==0) continue;//跳过未标记和无法到达的点
        vis[i] = 1;//标记
        a[pos+1] = i;//记录结果
        dfs(i,pos+1);
        vis[i] = 0;//取消标记
    }
}
int main() {
    for(int i = 1;i <= 20;i++) {
        for(int j = 1;j <= 3;j++) {
            int tmp;
            cin>>tmp;
            g[i][tmp] = 1;
        }
    }
    while(cin>>m&&m) {
        memset(vis,0,sizeof(vis));//初始化
        a[1] = m;//记录起点
        vis[m] = 1;//标记起点！！
        cnt = 0;//cnt计数，表示当前的路径数
        dfs(m,1);
    }
    return 0;
}
