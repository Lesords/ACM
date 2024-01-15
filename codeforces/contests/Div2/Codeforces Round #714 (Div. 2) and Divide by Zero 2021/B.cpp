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

//题解：由于题目需要各个位置 前的与结果 和 后的与结果 相等
//那么最后的结果肯定为 所有数的与结果 ！！！
//所以只需要计算 所有数的与结果 的数量num，将其放置首尾两端，然后中间任意排序即可
//即结果为： (num*(num-1)*(n-2)!)%MOD   num选两个放置两端*剩余数的全排列
//注意：当数据只有两个的时候，中间值应该为1而不是0！！！

const int MAXN = 2e5+5;
const ll MOD = 1e9+7;
ll a[MAXN],sum[MAXN];//若用sum预处理阶乘的话，需初始化sum[0] = sum[1] = 1！！！
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,num = 0;
        cin>>n;
        ll ans;//计算最终的 与结果
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            if(i==1) ans = a[i];
            else ans &= a[i];
        }
        for(int i = 1;i <= n;i++) {
            if(a[i]==ans) num++;//统计 与结果 出现的次数
        }
        ll siz = (num*(num-1ll))%MOD;//先计算两端的值
        for(int i = 1;i <= n-2;i++) {//然后再计算阶乘（中间部分）
            siz = (siz*i)%MOD;
        }
        cout<<siz<<"\n";
    }
	return 0;
}
