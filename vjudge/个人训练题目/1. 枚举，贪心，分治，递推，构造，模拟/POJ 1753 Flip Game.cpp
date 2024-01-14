#include<iostream>//ac
#include<cstring>
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：状态压缩所有的位置，然后记录翻转次数最少的即可
//翻转过程中，如果上一行的字符不符合条件，则当前状态无解

int nextt[5][2] = {0,0,0,1,0,-1,1,0,-1,0};//五个位置（包括当前位置）
char s[6][6];
int a[6][6];//操作数组 b为1，w为0
void change(int x,int y) {//修改五个位置的值
    for(int i = 0;i < 5;i++) {
        int tx = x+nextt[i][0];
        int ty = y+nextt[i][1];
        if(tx<1||tx>4||ty<1||ty>4) continue;//越界
        a[tx][ty] ^= 1;//取反即可
    }
}
int solve(int state,int op) {//当前状态为state，目标字符为op
    int cnt = 0;
    for(int i = 1;i <= 4;i++)
        for(int j = 1;j <= 4;j++) a[i][j] = s[i][j]=='b'?1:0;
    for(int i = 0;i < 16;i++) {
        if((state>>i)&1) {//第i个翻转
            int x = i/4+1;
            int y = i%4+1;
            change(x,y);
            if(x>1&&a[x-1][y]!=op) return INF;//上一个不满足条件，则无解（INF）
            cnt++;
        }
    }
    for(int i = 1;i <= 4;i++)
        for(int j = 1;j <= 4;j++) if(a[i][j]!=op) return INF;//不满足条件
    return cnt;
}
int main() {
    for(int i = 1;i <= 4;i++) cin>>s[i]+1;
    int ans = INF;
    for(int i = 0;i < (1<<16);i++) {
        ans = min(ans,solve(i, 1));//b
        ans = min(ans,solve(i, 0));//w
    }
    if(ans==INF) cout<<"Impossible";
    else cout<<ans;
    return 0;
}
