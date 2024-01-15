#include<cstdio>//ac
#include<iostream>
#include<algorithm>
using namespace std;
int vis[11][11][11][11][5][5];//专家的坐标，牛的坐标，专家的方向，牛的方向
int fx,fy,fdir,cx,cy,cdir;
int nextt[4][2] = {-1,0,0,1,1,0,0,-1};//向上、右、下、左 (0,1,2,3) 走！！！
char s[12][12];
bool judge() {//判断是否抓到牛了
    if(fx==cx&&fy==cy) return 0;
    return 1;
}
void change() {//移动牛和人的位置
    int tx = fx+nextt[fdir][0];
    int ty = fy+nextt[fdir][1];//人走向的位置
    //判断是否越界或者墙，是则转向，否则前进
    if(tx<1||tx>10||ty<1||ty>10||s[tx][ty]=='*') fdir = (fdir+1)%4;
    else fx = tx,fy = ty;
    tx = cx+nextt[cdir][0];
    ty = cy+nextt[cdir][1];//牛走向的位置
    if(tx<1||tx>10||ty<1||ty>10||s[tx][ty]=='*') cdir = (cdir+1)%4;
    else cx = tx,cy = ty;
}
int main() {
    for(int i = 1;i <= 10;i++) scanf("%s",s[i]+1);//存图
    for(int i = 1;i <= 10;i++) {
        for(int j = 1;j <= 10;j++) {//找牛和人的位置
            if(s[i][j]=='F') fx=i,fy=j;
            if(s[i][j]=='C') cx=i,cy=j;
        }
    }
    int flag = 0,ans = 0;//flag判断是否有解
    fdir = cdir = 0;//初始方向向上
    while(judge()) {//还未抓到就继续
        if(vis[fx][fy][cx][cy][fdir][cdir]++) {//重复的位置和方向则说明无解！！！
            flag = 1;break;
        }
        ans++;
        change();
    }
    cout<<(flag?0:ans);
    return 0;
}
