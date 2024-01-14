#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

//题解：SG函数
//由于最后剪出1*1的格子即为胜利
//所以对于所有的1*n或者n*1的格子来说都是必胜态
//那么这两个必胜态又可以由 2*2,2*3,3*2 来推出来
//因为这三种状态，不管怎么剪都会形成 1*n 或者 n*1
//也就是说这三个状态的后继状态都为必胜态，则这三个状态都为必败态！！！
//那么对于其他状态而言，由于操作都是最优的
//所以肯定从长度为2开始剪
//需要注意的是，当剪成两个部分时，这两个部分都可以被后一个人选择，所以需要取异或值！！！
//那么对于当前状态而言，可以计算所有后继状态的值即SG，然后取MEX
//利用记忆化可以加快速度！！！

const int MAXN = 205;
int sg[MAXN][MAXN];//存储对应 n*m 格子的状态 非0为必胜，0位必败
bool f[MAXN];//最大应该只有67！！！
int SG(int n,int m) {
    //先判断是否计算过，TLE了一万年！！！
    if(sg[n][m]!=-1) return sg[n][m];
    memset(f, 0, sizeof(f));//清空
    //从2开始，因为1*n为必胜态！！！
    //由于分割成两部分，所以按照升序计算不会重复
    //左边为i，右边为n-i（下一个类似）
    for(int i = 2;i <= n-i;i++) f[SG(i,m)^SG(n-i,m)] = 1;//记录所有出现的值为1
    for(int i = 2;i <= m-i;i++) f[SG(n,i)^SG(n,m-i)] = 1;//两个部分进行异或
    int pos = 0;//从0开始计算不在集合中的值
    while(f[pos]) pos++;//如果为1，表示当前值出现过，则继续往下找
    return sg[n][m] = pos;//返回并记录值
}
int main() {
    int n,m;
    memset(sg, -1, sizeof(sg));//初始化赋值为-1
    sg[2][2] = sg[2][3] = sg[3][2] = 0;//记录必败态
    while(scanf("%d%d",&n,&m)!=EOF) {
        puts(SG(n,m)?"WIN":"LOSE");//不为0即为必胜态，否则为必败态
    }
    return 0;
}
