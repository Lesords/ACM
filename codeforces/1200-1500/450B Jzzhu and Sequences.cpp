#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：根据 f[i] = f[i-1]+f[i+1] 可以计算出每6个数循环
//所以可以先计算这六个数，然后取模
//小技巧：第六个数可以理解为第0个数，故可直接取模6
//由于MOD只有1e9+7，但是最小值可以为 -2e9 ，所以取模需要两个MOD和

const int MOD = 1e9+7;
ll a[8];
int main() {
    ll x,y,n;
    cin>>x>>y>>n;
    a[1] = x;//先计算6个数
    a[2] = y;
    a[3] = y-x;
    a[4] = -x;
    a[5] = -y;
    a[0] = -y+x;//第六个数移到第零个，故可直接取模6
    //取模需要两个MOD！！！
    cout<<(a[n%6]+MOD+MOD)%MOD<<"\n";
    return 0;
}
