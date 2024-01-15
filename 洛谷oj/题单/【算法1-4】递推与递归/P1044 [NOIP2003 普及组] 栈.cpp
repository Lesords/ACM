#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：记忆化搜索
//设f[i][j]为队列中剩余i个，栈中有j个的情况数
//边界状态：当队列中剩余0个时，剩余情况只有1种，即将栈中数据全部弹出
//那么对于剩余状态分为两种：栈中有数据和栈中无数据
//栈中有数据的话：f[i][j] += f[i][j-1]      弹出栈中的数据
//栈中无数据的话：f[i][j] += f[i-1][j+1]    将队列中的数据移到栈中
//对于已经计算过的，直接返回结果

ll f[20][20];
ll dfs(int a,int b) {//队列中有a个，栈中有b个
    if(f[a][b]) return f[a][b];//已计算过，直接返回
    if(a==0) return 1;//边界0的值为1
    if(b) f[a][b] += dfs(a,b-1);//如果栈中存在值，就可以把栈中数据直接弹出
    f[a][b] += dfs(a-1,b+1);//把队列中的数移到栈中
    return f[a][b];
}
int main() {
    int n;
    cin>>n;
    cout<<dfs(n,0);
    return 0;
}
