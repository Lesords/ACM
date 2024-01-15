#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：由于每次的操作不需要连续的段，所以只需要找到最大的差值即可
//然后利用二进制来判断到底操作了多久（二进制几位就几秒，取决于最高位）

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        int maxx = 0,ans = 0,last = -INF;//last为前面的最大值
        for(int i = 1;i < n;i++) {
            if(a[i]>a[i+1]) {//不为升序
                last = max(last, a[i]);//更新较大值
                maxx = max(maxx, last-a[i+1]);//计算最大差值
            }
        }
        while(maxx) {//计算maxx有几位，即需要几秒
            ans++;
            maxx >>= 1;
        }
        cout<<ans<<"\n";
    }
    return 0;
}
