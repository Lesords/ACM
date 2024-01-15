#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：数位中最小值*最大值，如果最小值为0，则最终值即为本身
//由于最小值最后总会为0，所以直接算就可以了

ll solve(ll val) {//计算最小值和最大值的乘积
    int minn = 11, maxx = 0;
    while(val) {
        int tmp = val%10;
        minn = min(minn,tmp);
        maxx = max(maxx,tmp);
        val /= 10;
    }
    return minn*maxx;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll a,k;
        cin>>a>>k;
        while(--k) {//找第k个
            ll add = solve(a);//增加的值
            if(add==0) break;//若为0，则结束即可
            a += add;
        }
        cout<<a<<"\n";
    }
    return 0;
}
