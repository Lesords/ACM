#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：根据编号大小排序
//然后每个位置可以选的可能性为：当前值 - 已经选择的数量（即前面的数量
//所有位置相乘取模即为结果

const int MOD = 1000000007;
int a[55];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+1+n);//从小到大排序
    ll ans = 1;
    for(int i = 1;i <= n;i++) {
        //当前位置的可能性为：a[i]-i+1
        //前面有(i-1)个
        ans = (ans*(a[i]-i+1))%MOD;
    }
    cout<<ans;
    return 0;
}
