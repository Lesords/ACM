#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：四根木棒组成正三角形，所以必须有两个木棒相等，且另外两个相加与其相等
//数据范围只有5e3，所以可以直接枚举 相同的木棒 和 拼接的木棒

const int MAXN = 5e3+5;
const ll MOD = 1e9+7;
ll num[MAXN];//记录每种长度的木棒出现的次数
ll solve(ll num) {//从num个木棒中选出2个的组合数
    //c(2,num) = a(2,num)/a(2,2) = num*(num-1) / 2;
    return num*(num-1ll)/2%MOD;//不能先除2，会向下取整！！！
}
int main() {
    int n,tmp,maxx = 0;//maxx记录最长的木棒长度
    ll ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>tmp,num[tmp]++;//记录木棒出现的次数
        maxx = max(tmp,maxx);
    }
    for(int i = 2;i <= maxx;i++) {//枚举相同的木棒
        if(num[i]<2) continue;//少于两个跳过
        ll tri = solve(num[i])%MOD;//计算相同木棒的组合数
        for(int j = 1;j <= i/2;j++) {//从1遍历到一半
            //拼接的木棒相同
            if(j*2==i&&num[j]>=2) ans += tri*solve(num[j])%MOD;
            //拼接的木棒不相同
            if(j*2!=i&&num[j]&&num[i-j]) ans += tri*num[j]%MOD*num[i-j]%MOD;
            ans %= MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}
