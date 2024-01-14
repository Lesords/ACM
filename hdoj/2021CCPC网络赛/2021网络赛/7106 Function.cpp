#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x7f7f7f7f7f7f7f7f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
using namespace std;

//题解：	由于最大的数为 999999，对应的g(999999) = 54
//所有可以遍历所有的 g(x)，使得g(x)成为定值
//则有 f(x) = a*x*x*g(x) + b*x*x + c*x*g(x)*g(x) + d*x*g(x)
//    = x*x * (a*g(x) + b) + x* (c*g(x)*g(x) + d*g(x))
//令 A = a*g(x) + b, B = c*g(x)*g(x) + d*g(x)
// f(x) = A * x*x + B * x

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
vector<int> g[60];//记录对应g(x)的x
int cal(int val) {//计算val的数位和
	int ans = 0;
	while(val) {
		ans += val%10;
		val /= 10;
	}
	return ans;
}
void init() {//初始化将所有x存在g(x)
	for(int i = 1;i <= int(1e6);i++) {
		g[cal(i)].push_back(i);
	}
}
ll fun(ll a,ll b,ll x) {//计算函数和
	return x*x*a + x*b;
}
int main() {
	fast;
	init();
    int t;
    cin>>t;
    while(t--) {
    	ll a,b,c,d,n;
    	cin>>a>>b>>c>>d>>n;
    	ll ans = LINF;
    	for(int i = 1;i <= 54;i++) {
    		if(g[i].empty()) continue;//跳过空的位置（表示无对应值）
    		if(g[i][0]>n) break;
    		ll A = a*i + b;
    		ll B = c*i*i + d*i;
    		//右边界需要划定，否则会出现右边界大于n的情况！！！
   			int l = 0, r = upper_bound(g[i].begin(), g[i].end(), n)-g[i].begin()-1;//大于n的位置，前移一位
    		if(A<=0) {//小于0，开头向下（最小值存在左右两边）；等于0为单调函数（最小值也存在左右两边）
    			ans = min({ans, fun(A, B, g[i][0]), fun(A, B, g[i][r])});
    		}
    		else {
    			//三分
    			while(l < r) {
    				int m1 = l + (r-l)/3;//第一个位置
    				int m2 = r - (r-l)/3;//第二个位置
    				if(fun(A, B, g[i][m1]) > fun(A, B, g[i][m2])) l = m1+1;//把值大的减掉
    				else r = m2-1;
    			}
    			//取两个边界的最小值即可
    			ans = min({ans, fun(A, B, g[i][l]), fun(A, B, g[i][r])});
    		}
    	}
    	cout<<ans<<"\n";
    }
    return 0;
}
