#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN],n,c;
int main() {
    ll ans = 0;//输入32位，结果爆int
    cin>>n>>c;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+n+1);//从小到大排序
    for(int i = 1;i < n;i++) {
        //遍历所有数，计算可以与其配对的数的数量
        int l = lower_bound(a+i+1,a+n+1,c+a[i])-a;//第一个大于等于 x
        int r = upper_bound(a+i+1,a+n+1,c+a[i])-a;//第一个大于 x
        ans += r-l;//相减即为可匹配数
    }
    cout<<ans<<endl;
    return 0;
}
