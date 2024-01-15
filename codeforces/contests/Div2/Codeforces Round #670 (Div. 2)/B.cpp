#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
ll val_a[MAXN],val_b[MAXN];
bool cmp(ll a,ll b) {//从大到小排序规则
    return a > b;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;cin>>n;
        ll cnt_a = 0,cnt_b = 0,tmp;
        for(int i = 1;i <= n;i++) {
            cin>>tmp;
            //val_a 保存非负数，val_b保存负数
            if(tmp>=0) val_a[++cnt_a] = tmp;
            else if(tmp<0) val_b[++cnt_b] = tmp;
        }
        ll ans = -INF;
        sort(val_a+1,val_a+cnt_a+1,cmp);//非负数从大到小排序
        sort(val_b+1,val_b+cnt_b+1);//负数从小到大排序
        if(n==5) {//只有5个数的时候
            ll now = 1;
            for(int i = 1;i <= cnt_a;i++) now *= val_a[i];
            for(int i = 1;i <= cnt_b;i++) now *= val_b[i];
            ans = max(ans,now);
        }
        if(cnt_a>=5) {//非负数超过5个
            ll now = 1;
            for(int i = 1;i <= 5;i++) now *= val_a[i];
            ans = max(ans,now);
        }
        if(cnt_a>=3&&cnt_b>=2) {//3个非负2个负，结果也为正
            ll now = 1;
            for(int i = 1;i <= 3;i++) now *= val_a[i];
            for(int i = 1;i <= 2;i++) now *= val_b[i];//两个绝对值大的负数
            ans = max(ans,now);
        }
        if(cnt_a>=1&&cnt_b>=4) {//1个正4个负，结果为正
            ll now = val_a[1];
            for(int i = 1;i <= 4;i++) now *= val_b[i];//四个绝对值大的负数
            ans = max(ans,now);
        }
        if(cnt_b>=5) {//5个负数
            ll now = 1;
            //只有5个负数时，选绝对值越小，所得的结果越大
            for(int i = cnt_b;i >= cnt_b-4;i--) now *= val_b[i];
            ans = max(ans,now);
        }
        cout<<ans<<"\n";
    }
	return 0;
}
