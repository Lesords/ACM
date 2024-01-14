#include<iostream>//ac
#include<string>
#include<algorithm>
#define ll long long
using namespace std;//数据范围有点大

//题解：题目只需要最后一个值为true即可！！！

ll dp[100];//dp[i]表示i位置为true的数量
int main() {
    int n;
    cin>>n;
    dp[0] = 1;//初始位置只有一个（只能对应赋值）
    for(int i = 1;i <= n;i++) {
        string tmp;
        cin>>tmp;
        if(tmp=="AND") {//若为and，则当前和上一个必须为true
            dp[i] = dp[i-1];
        }
        else dp[i] = dp[i-1]+(1ll<<i);
        //由于只需要最后一个为true，所以OR运算中
        //当前位置为true的话，则前面 0-(n-1) 的值可以为任意值
        //当前位置为false的话，则上一个必须为true
    }
    cout<<dp[n];
    return 0;
}
