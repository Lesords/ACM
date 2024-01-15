#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：初始化每行白和蓝和红的数量（可用前缀和优化），暴力枚举蓝和红的起点
//计算所需要的数量，取较小值即可

char map[55][55];
int white[55],blue[55],red[55],n,m;
int solve(int one,int two) {//one是蓝色起点，two是红色起点
    int num = 0;
//    前缀和做法
//    num += blue[one-1]+red[one-1];//上部分白色
//    num += white[two-1]-white[one-1]+red[two-1]-red[one-1];//中间蓝色
//    num += white[n]-white[two-1]+blue[n]-blue[two-1];//下部分红色
    for(int i = 1;i < one;i++) num += blue[i]+red[i];//白色部分
    for(int i = one;i < two;i++) num += white[i]+red[i];//蓝色部分
    for(int i = two;i <= n;i++) num += white[i]+blue[i];//红色部分
    return num;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        int wt = 0,bl = 0,rd = 0;
        for(int j = 1;j <= m;j++) {
            cin>>map[i][j];
            if(map[i][j]=='W') wt++;
            else if(map[i][j]=='B') bl++;
            else rd++;
        }
        white[i] = wt;//记录当前行的对应颜色方块的数量
        blue[i] = bl;
        red[i] = rd;
//        white[i] = white[i-1]+wt;//前缀和写法
//        blue[i] = blue[i-1]+bl;
//        red[i] = red[i-1]+rd;
    }
    int ans = INF;
    for(int i = 2;i <= n-1;i++) {//枚举所有起点的可能性
        for(int j = i+1;j <= n;j++) {
            ans = min(ans,solve(i,j));//取最小值
        }
    }
    cout<<ans<<endl;
    return 0;
}
