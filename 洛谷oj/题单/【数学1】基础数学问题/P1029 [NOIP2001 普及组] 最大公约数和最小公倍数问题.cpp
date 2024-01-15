#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;

//题解：最大公约数*最小公倍数 = 原两个数的乘积 ！！！
//所以先计算两个数的乘积，最后再遍历这个乘积的所有因子
//判断符合情况的数量，需要注意平方数

ll gcd(ll a,ll b) {//求最大公约数
    return b==0?a:gcd(b,a%b);
}
int main() {
    int a,b;
    cin>>a>>b;
    ll val = a*1ll*b;//两个数的乘积
    int n = sqrt(val);
    int ans = 0,vis = 0;//vis判断是否有平方数
    for(int i = 1;i <= n;i++) {//遍历所有因子
        //i为val的因子
        if(val%i==0&&gcd(i,val/i)==a) {//a是最大公约数！！！
            ans++;
            if(i*1ll*i==val) vis++;//为平方数
        }
    }
    cout<<ans*2-vis;//交换位置也算一次，所以需*2，扣除有平方数的情况
    return 0;
}
