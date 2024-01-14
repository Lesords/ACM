#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN];
int main() {
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        ans = max(ans, a[i]);
    }
    for(int i = 1;i <= n;i++) {//暴力求区间最值即可
        int tmp = a[i];
        for(int j = i+1;j <= n;j++) {
            tmp = min(tmp, a[j]);//i-j范围内最小的橘子数
            ans = max(ans, tmp*(j-i+1));//更新最值
        }
    }
    cout<<ans;
    return 0;
}
