#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//题解：二分答案+前缀和技巧判定
//以(-1e6, 1e6)区间二分答案
//由于需要平均数为mid，所以可以先把所有的数减去mid
//那么可以转换为是否存在区间长不小于f的和大于等于0的区间
//每次以f区间来更新，前面的最小值，不断更新答案即可

const int MAXN = 1e5+5;
double a[MAXN],pre[MAXN];
int main() {
    ios::sync_with_stdio(0);//加速
    cin.tie(0),cout.tie(0);
    int n,f;
    cin>>n>>f;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    double l = -1e6,r = 1e6,ans;
    while(r-l>1e-5) {//精度在要求上加两位
        double mid = (l+r)/2;
        for(int i = 1;i <= n;i++) {//前缀和处理，扣除mid
            pre[i] = pre[i-1] + a[i] - mid;
        }
        double num = -1e10,minn = 1e10;//初始化尽量开大点
        for(int i = f;i <= n;i++) {//最短为f，所以从f开始遍历
            minn = min(minn, pre[i-f]);//更新前面（左边起点）的较小值
            num = max(num, pre[i]-minn);//更新答案
        }
        if(num>=0) ans = mid,l = mid;//l在扩大区间，r在缩小，所以取r值较准确
        else r = mid;
    }
//    cout<<int(ans*1000);//wa
    cout<<int(r*1000);//ac
    return 0;
}
