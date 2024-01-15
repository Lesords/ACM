#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e6+6;
int a[MAXN];
int main() {
    int n,minn = INF,ans = 0;//最小值初始化为INF，结果初始化为0（可为-INF）
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        minn = min(minn,a[i]);//记录最小值
        ans = max(ans,a[i]-minn);//取 当前值-最小值 的较大值
    }
    cout<<ans<<endl;
    return 0;
}
