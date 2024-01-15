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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//题解：直接暴力计算每个位置赚到c需要花费的时间
//用sum来记录当前剩余的金钱，用day来记录经历的天数
//注意：(x+a[i]-1ll)/a[i] -> 向上取整的技巧

const int MAXN = 2e5+5;
int a[MAXN],b[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,c;
        cin>>n>>c;
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i < n;i++) cin>>b[i];
        ll sum = 0,day = 0,ans = 1e18;//ans初始化为正的，结果取小的！！！
        for(int i = 1;i <= n;i++) {//从前往后遍历
            //在当前位置学习需要再花多少天
            ans = min(ans, (c-sum+a[i]-1ll)/a[i]+day);//取小值
            //跳过下一个位置，需要在当前位置学多少天
            ll need = max(0ll,(b[i]-sum+a[i]-1ll))/a[i];//与0取较大值，防止负数
            day += need+1;//need为学习的天数，+1为移动的天数
            sum += (need*a[i]-b[i]);//更新剩余金钱值
        }
        cout<<ans<<"\n";
    }
	return 0;
}
