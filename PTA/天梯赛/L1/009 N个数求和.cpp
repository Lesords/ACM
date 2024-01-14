#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
struct node{
    ll x,y;
}a[105];
ll gcd(ll a,ll b) {//最大公因数
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b) {//最小公倍数
    return a*b/gcd(a,b);
}
int main() {
    int n,flag = 0;
    ll down = 1,up = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        scanf("%lld/%lld", &a[i].x,&a[i].y);
        down = lcm(a[i].y,down);//计算所有分母的最小公倍数
    }
    for(int i = 1;i <= n;i++) {//然后再计算的分子的大小
        up += down/a[i].y*a[i].x;
    }
    ll com = gcd(up,down);//分子分母约分
    up /= com;
    down /= com;
    if(up/down) cout<<up/down,flag = 1;//不为0，则输出对应部分
    if(up%down) {
        if(flag) cout<<" ";
        cout<<up%down<<"/"<<down<<endl;
    }
    else if(!flag) cout<<"0";//最后一个样例的结果为0，需要特判！！！
    return 0;
}
/*
2 -2/3 2/3
*/
