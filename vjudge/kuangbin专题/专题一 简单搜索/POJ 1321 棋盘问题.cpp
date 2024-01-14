#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;
char s[10][10];
int n,m,ans,vis[10];
void dfs(int now,int num) {//now为当前行，num为当前已摆放的数量
    if(now>n+1) return;//n+1行才为结束点！！！
    if(num==m) {//满足条件
        ans++;return;
    }
    for(int i = 1;i <= n;i++) {//遍历当前行的所有列
        if(vis[i]||s[now][i]=='.') continue;//当前列已放过，或为空
        vis[i] = 1;//标记
        dfs(now+1,num+1);
        vis[i] = 0;//回溯取消标记
    }
    dfs(now+1,num);//当前行无棋盘区域，可直接移到下一行
}
int main() {
    while(cin>>n>>m) {
        if(n==-1&&m==-1) break;
        for(int i = 1;i <= n;i++) cin>>s[i]+1;
        memset(vis,0,sizeof(vis));//初始化
        ans = 0;//初始化为0
        dfs(1,0);
        cout<<ans<<'\n';
    }
    return 0;
}
