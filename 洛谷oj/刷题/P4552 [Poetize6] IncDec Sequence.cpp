#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;

//题解：所有的数字相同，对于差分来说，即差分的结果都为0
//所以可以先求原数组的差分，让每个正数与一个负数对应
//剩余的即为同号数字，可用前缀或后缀来处理
//所以操作数为 max(正数差分和，负数差分和)
//情况数为 abs(正数差分和-负数差分和)+1

//例子：3 2 2 2 6
// 3 3 3 3 6
//最后的结果可以为 3 4 5 6，即四种 = （4-1）+1


const int MAXN = 1e5+5;
ll a[MAXN],d[MAXN];//d为差分数组
int main() {
    ll n,up = 0,down = 0;//up计算正数和，down就算负数和
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        if(i==1) d[i] = a[i];//第一个即为数组本身
        else {
            d[i] = a[i]-a[i-1];//计算差分
            if(d[i]>0) up += d[i];//正数则直接加
            else down -= d[i];//负数的话需要减，负负得正
        }
    }
    cout<<max(up,down)<<"\n"<<llabs(up-down)+1;
    return 0;
}
