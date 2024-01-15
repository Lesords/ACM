#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：先预处理前缀和，接着遍历左端点，然后二分右端点
//取满足条件的最大的区间长度即为答案

const int MAXN = 1e5+5;
int a[MAXN], sum[MAXN];
int main() {
    int n,t;
    cin>>n>>t;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 1;i <= n;i++) sum[i] = sum[i-1]+a[i];//前缀和
    int ans = 0;//前缀和预处理，可快速计算区间内的书所花的时间
    for(int i = 1;i <= n;i++) {
        int l = i, r = n;//可能会出现1的情况，所以起点为i
        while(l<=r) {
            int mid = (l+r)>>1;
            //i-mid区间内的时间小于t，则l+（右移），否则r-（左移）
            if(sum[mid]-sum[i-1]<=t) ans = max(ans,mid-i+1), l = mid+1;
            else r = mid-1;//ans更新最值
        }
    }
    cout<<ans<<"\n";
    return 0;
}
