#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：遍历n的所有因子，计算最小的因子（对应的另外一个因子小于k）

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k,ans = INF;
        cin>>n>>k;//k为容量大小
        for(int i = 1;i*i <= n;i++) {
            if(n%i==0) {//一次检查两个因子
                if(n/i<=k) ans = min(ans,i);//i个 n/i 大小的包
                if(i<=k) ans = min(ans,n/i);//n/i个 i 大小的包
            }
        }
        cout<<ans<<"\n";//求最少个数
    }
    return 0;
}
