#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;

//题解：可以直接用贪心法求解
//由于匹配的条件是差值小于等于1
//所以可以将男生和女生都对应从小到大排序
//每个男生选择尽量小的女生
//则对应满足条件的队数即为结果

int a[105],b[105],vis[105];
int main() {
    int n,m,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    cin>>m;
    for(int i = 1;i <= m;i++) cin>>b[i];
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);//排序
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {//寻找对应的女生
            if(vis[j]) continue;//跳过已标记的（已组队的）
            if(abs(a[i]-b[j])<=1) {//满足条件
                ans++;
                vis[j] = 1;//标记
                break;
            }
        }
    }
    cout<<ans;
    return 0;
}
