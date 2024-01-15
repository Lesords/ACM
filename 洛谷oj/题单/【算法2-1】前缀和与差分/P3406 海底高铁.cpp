#include<iostream>//ac 差分前缀和+贪心
#include<algorithm>
#define ll long long
using namespace std;

//题解：利用差分+前缀和来计算每段路经过的次数
//然后遍历所有的路段利用贪心来判断用哪种方式付款

const int MAXN = 1e5+5;
ll dif[MAXN],sum[MAXN];//dif差分，sum前缀和
int main() {
    int n,m;
    cin>>n>>m;
    ll last = 0,tmp;//last保存上一个城市的号码
    for(int i = 1;i <= m;i++) {
        cin>>tmp;
        if(i==1) {//跳过第一个
            last = tmp;continue;
        }
        //判断两个城市间的大小（方向）
        if(last<tmp) dif[last]++,dif[tmp]--;//末尾城市道路不经过！！！
        else dif[tmp]++,dif[last]--;
        last = tmp;//更新上一个城市的号码
    }
    for(int i = 1;i <= n;i++) {//前缀和求次数
        sum[i] = sum[i-1]+dif[i];
    }
    ll ans = 0;
    for(int i = 1;i < n;i++) {
        ll a,b,c;
        cin>>a>>b>>c;//方案1只需要a，方案2需多花c元！！！
        ans += min(a*sum[i],b*sum[i]+c);//取小值
    }
    cout<<ans;
    return 0;
}
