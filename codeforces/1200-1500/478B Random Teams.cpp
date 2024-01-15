#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：最小的情况是尽量均分；最大的情况是其他为1，剩余的组成一队
//然后用组合数学求解：n*(n-1)/2 为朋友对数

ll getmin(ll a,ll b) {//求小值
    ll num = a/b;
    ll rest = a%b;
    if(rest==0) {//没有剩余的时候，即为b个含有num个人的队伍
        return b*(num*(num-1))/2;
    }
    else {//为rest个num+1的队伍数，(b-rest）个num的队伍数！！！
        num++;
        return (rest)*(num*(num-1))/2+(b-rest)*(num-1)*(num-2)/2;
    }
}
int main() {
    ll n,m;
    cin>>n>>m;//最大的情况：剩余一队的数量为 n-m+1（扣除m-1个）
    cout<<getmin(n,m)<<" "<<(n-m)*(n-m+1)/2<<"\n";
    return 0;
}
