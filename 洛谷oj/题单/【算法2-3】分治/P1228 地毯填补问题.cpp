#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：分治法将原来的迷宫分成四部分
//根据已填写的位置来放置地毯，分界位置不包括已填写的位置（拐角在斜对线
//计算中间点（左上角区间的右下角位置），起点+长度的一半-1！！！
//然后在维护四个位置的数据既可

int k,px,py,width;//width为宽度，(px,py)为公主的位置
void dfs(int x,int y,int sx,int sy,int len) {
    //(x,y)为已填写的位置 (sx,sy)为区间左上角的坐标，len为区间长度
    if(len==1) return;//区间为1，则跳过
    int midx = sx+len/2-1;//计算中间点！！（用len的一半来计算）
    int midy = sy+len/2-1;
    if(x<=midx&&y<=midy) {//左上角区间已填写
        cout<<midx+1<<" "<<midy+1<<" 1\n";//地毯放置在右下角位置
        dfs(x,y,sx,sy,len/2);//更新对应填写的位置和起点位置
        dfs(midx,midy+1,sx,sy+len/2,len/2);
        dfs(midx+1,midy,sx+len/2,sy,len/2);
        dfs(midx+1,midy+1,sx+len/2,sy+len/2,len/2);
    }
    if(x<=midx&&y>midy) {//右上角区间已填写
        cout<<midx+1<<" "<<midy<<" 2\n";//地毯放置在左下角位置
        dfs(midx,midy,sx,sy,len/2);
        dfs(x,y,sx,sy+len/2,len/2);
        dfs(midx+1,midy,sx+len/2,sy,len/2);
        dfs(midx+1,midy+1,sx+len/2,sy+len/2,len/2);
    }
    if(x>midx&&y<=midy) {//左下角位置已填写
        cout<<midx<<" "<<midy+1<<" 3\n";//地毯放置在右上角位置
        dfs(midx,midy,sx,sy,len/2);
        dfs(midx,midy+1,sx,sy+len/2,len/2);
        dfs(x,y,sx+len/2,sy,len/2);
        dfs(midx+1,midy+1,sx+len/2,sy+len/2,len/2);
    }
    if(x>midx&&y>midy) {//右下角位置已填写
        cout<<midx<<" "<<midy<<" 4\n";//地毯放置在左上角位置
        dfs(midx,midy,sx,sy,len/2);
        dfs(midx,midy+1,sx,sy+len/2,len/2);
        dfs(midx+1,midy,sx+len/2,sy,len/2);
        dfs(x,y,sx+len/2,sy+len/2,len/2);
    }
}
int main() {
    cin>>k>>px>>py;
    width = 1<<k;//计算区间长度
    dfs(px,py,1,1,width);
    return 0;
}
