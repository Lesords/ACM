#include<iostream>//ac
#include<cstring>
#include<cstdlib>
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
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
#define lson rt<<1
#define rson rt<<1|1
using namespace std;
const int MAXN = 505;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int day[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};//记录对应月份的天数
struct cake{
	int time, cost, val;//time为生日时间（一年中的对应天数），cost为蛋糕花费天数，val为好感值
	friend bool operator < (cake a, cake b) {
		return a.time < b.time;//根据时间从小到大排序
	}
}a[MAXN];
struct gift {
	int cost, val;//cost为礼物价格，val为好感值
}b[20];
int f[20], dp[MAXN][20][366];//f[i]表示购买i个礼物的最大好感值
//dp[i][j][k]：表示前i个同学中j个购买礼物（即不做蛋糕），并且过了k天的最大好感值
void solve() {
	int n, m, w, cnt = 0;//cnt记录有效的学生数量（忽略2月29日的学生）
	cin >> n >> m >> w;
	memset(f, 0, sizeof(f));//因为不存在负数，所以直接初始化为0即可
	memset(dp, 0, sizeof(dp));
	for(int i = 1;i <= n;i++) {
		int y, m, d, c, v;
		scanf("%d-%d-%d %d %d", &y, &m, &d, &c, &v);
		if(m==2&&d==29) continue;//跳过2月29日的学生
		int now = day[m-1]+d;//上个月的累计天数+这个月过的天数
		a[++cnt] = {now, c, v};
	}
	sort(a+1, a+cnt+1);
	for(int i = 1;i <= m;i++) {
		cin >> b[i].cost >> b[i].val;
	}
	//由于礼物最多只有15个，所以可以二进制枚举所有情况，计算购买对应数量的礼物的最大好感值
	for(int i = 0;i < (1<<m);i++) {
		int sum = 0, val = 0, num = 0;//sum为总花费，val为总好感值，num为购买的数量
		for(int j = 0;j < m;j++) {//逐位判断（共m位，从0位开始即当前位）
			if(1<<j & i) {
				num++;
				val += b[j+1].val;
				sum += b[j+1].cost;
			}
		}
		if(sum <= w) f[num] = max(f[num], val);//在预算范围内，更新最大值
	}
	for(int i = 1;i <= cnt;i++) {
		for(int j = 0;j <= m;j++) {
			for(int k = 0;k <= 365;k++) {
				//当前位置不做蛋糕
				dp[i][j][k] = max(dp[i][j][k], dp[i-1][max(0, j-1)][k]);
				//当前位置做蛋糕
				//1. 需要满足上一个状态蛋糕数不超过总人数
				//2. 当前时间没有超过当前朋友的生日
				//3. 当前天数够制作当前蛋糕
				if(i-1>=j&&k<=a[i].time&&k>=a[i].cost) {
					dp[i][j][k] = max(dp[i][j][k], dp[i-1][j][k-a[i].cost] + a[i].val);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0;i <= m;i++) {//这里遍历的是购买礼物的个数（即不做蛋糕的数量）！！！
		for(int j = 0;j <= 365;j++) {
			ans = max(ans, dp[cnt][i][j] + f[i]);//朋友数量固定，其他两个变化
		}
	}
	cout << ans << "\n";
}
int main() {
	for(int i = 2;i <= 12;i++) {//累加，表示从头到当前月份末的天数
		day[i] += day[i-1];
	}
    int t;
    cin>>t;
    while(t--) {
    	solve();
    }
    return 0;
}
