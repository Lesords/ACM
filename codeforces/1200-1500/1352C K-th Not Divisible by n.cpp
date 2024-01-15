#include<iostream>//ac
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

//题解：二分解题，利用0-INF为二分的范围
//然后计算每个mid的位置是否满足k
//计算mid的位置为 mid - mid/n即可
//需要特判mid为n的倍数时，输出的值需-1！！！

ll n,k;
ll cal(ll val) {//计算val的位置
    return val-val/n;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        ll l = 0,r = INF;//二分范围为0-INF
        while(l<=r) {
            ll mid = (l+r)>>1;
            if(cal(mid)==k) {//位置满足条件时
                if(mid%n==0) cout<<mid-1<<"\n";//特判可以整除的情况！！！
                else cout<<mid<<"\n";
                break;
            }
            else if(cal(mid)>k) r = mid-1;//位置大了需左移
            else l = mid+1;//小了右移
        }
    }
    return 0;
}
