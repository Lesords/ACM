#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e6+5;
ll pre[MAXN],n;//注意long long！！！

//题解：前缀和处理+二分查找

int main() {
    for(int i = 1;i < MAXN;i++) pre[i] = pre[i-1]+i;//前缀和
    cin>>n;
    for(int i = 1;i < n;i++) {//遍历起点，二分终点
        ll l = i+1,r = n,ans = 0;//l从后一位开始
        while(l<=r) {//二分查找终点
            ll mid = (l+r)/2;
            ll tmp = pre[mid]-pre[i-1];//区间值
            if(tmp==n) {//相同即为终点
                ans = mid;break;
            }
            else if(tmp>n) r = mid-1;//大了前移，小了后移
            else if(tmp<n) l = mid+1;
        }
        if(ans) cout<<i<<' '<<ans<<endl;//非0即为找到答案
    }
    return 0;
}
