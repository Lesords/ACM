#include<iostream>//ac
#include<utility>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：暴力搜索，枚举每个位置的状态
//0表示当前为空
//1表示当前被一个1*1的正方形占用
//2表示当前格子(x,y)和下一个格子(x,y+1)被1*2的长方形占用（水平摆放
//3表示当前格子(x,y)和下一个格子(x+1,y)被1*2的长方形占用（垂直摆放
//从起始位(1,1)开始枚举，到达h+1行即为满足条件

int ans,num[25][25],h,w,a,b;
pii getN(int x,int y) {//获取下一个位置
    if(y==w) return {x+1,1};//如果当前位置在行末，则需移到下一行
    return {x,y+1};//否则右移即可
}
void dfs(int x,int y,int cnta,int cntb) {//(x,y)为当前坐标，cnta,cntb分别为a,b的剩余数量
    if(cnta<0||cntb<0) return;//小于0则不满足条件，跳过
    if(x>h) return (void) ans++;//满足条件结果累加（void小技巧
    pii nxt = getN(x,y);//获取下一个位置的坐标
    if(num[x][y-1]==2||num[x-1][y]==3) {//若当前位置被上一个或左边占用了，则无需填充，继续操作
        return dfs(nxt.fi,nxt.se,cnta,cntb);
    }
    num[nxt.fi][nxt.se] = 1;//放置1*1的格子
    dfs(nxt.fi,nxt.se,cnta,cntb-1);//cntb数量-1
    num[nxt.fi][nxt.se] = 0;//回溯
    if(y<w&&num[x-1][y+1]!=3) {//水平放置，则右边的上一个不得垂直放置
        num[x][y] = 2;//水平放置
        dfs(nxt.fi,nxt.se,cnta-1,cntb);//cnta的数量-1
        num[x][y] = 0;//回溯
    }
    if(x<h) {//下一行不越界即可
        num[x][y] = 3;//垂直放置
        dfs(nxt.fi,nxt.se,cnta-1,cntb);//cnta的数量-1
        num[x][y] = 0;//回溯
    }
}
int main() {
    cin>>h>>w>>a>>b;
    dfs(1,1,a,b);
    cout<<ans;//输出结果
    return 0;
}
