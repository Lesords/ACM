#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：由于要分成三段，所以总和需为3的倍数
//利用后缀和来判断最后一段可以构成的数量
//再利用前缀和来判断当前位置是否可以当成一个段

const int MAXN = 5e5+5;
ll a[MAXN],cnt[MAXN];
int main() {
    ll n, sum = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i],sum+=a[i];//计算总和
    if(sum%3) {//不为3的倍数，则无解
        cout<<"0\n";
    }
    else {
        sum /= 3;//除3得到每块的大小
        ll ss = 0,ans = 0;
        for(int i = n;i >= 1;i--) {//从后向前求前缀和（计算可行的最后一段）
            ss += a[i];//累加
            if(ss==sum) cnt[i] = 1;//可行，则标记
        }
        for(int i = n-1;i >= 1;i--) cnt[i] += cnt[i+1];//统计i位置及以后所有可行的数量
        ss = 0;//清零
        for(int i = 1;i <= n-2;i++) {//需要给后面留两个位置
            ss += a[i];
            if(ss==sum) {//当前位置可以分段，则统计后面可以匹配的数量
                ans += cnt[i+2];//需要给第二段留一位！！！
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
