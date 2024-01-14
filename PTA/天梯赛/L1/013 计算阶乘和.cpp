#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
    int n,ans = 0,tmp = 1;//ans计算总和，tmp计算当前阶乘值
    cin>>n;
    for(int i = 1;i <= n;i++) {
        tmp *= i;//乘
        ans += tmp;//累加
    }
    cout<<ans;
    return 0;
}
