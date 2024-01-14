#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int x,num = 1,val = 1;//初始化num和val都为1
    cin>>x;
    while(val<x) {//先使光棍数的值大于x
        val = val*10+1;
        num++;//num表示1的数量
    }
    while(val) {
        cout<<val/x;//整数部分
        val %= x;//取余数
        if(val==0) break;//余数为0，表示可整除，则到此结束
        val = val*10+1;//接下来的需要逐步除，不能跳过！！！
        num++;//因为部分答案可能有0，直接while会跳过0（样例！！！）
    }
    cout<<" "<<num;
    return 0;
}
