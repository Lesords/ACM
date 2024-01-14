// Problem: E - 7
// Contest: AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest 225)
// URL: https://atcoder.jp/contests/abc225/tasks/abc225_e
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-11-09 21:22:39

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

//题意：首先，需要知道 中心点+左边点+下方点 可以组成一个数字7
//那么，给定n个数字7的中心点，请问删除若干个数字7之后，从原点可以观察到7的数量为多少？

//题解：将数字7的 下方点与左边点 逐个与原点相连，那么会发现有其他数字7的两条线在其斜率范围内
//那么肯定会被当前数字7挡住
//所以，将整个坐标轴旋转45度观察，从x轴往y轴看，那么可以将问题转换为区间调度问题
//那么可以将所有的数字7按照末点从小到大排序；如果末点相等，则按照起点从小到大排序
//末点即左边点，起点即下方点

//然后从小到大开始遍历，记录 最近满足条件的数字7的末点信息
//判断当前点的起点信息是否 大于等于 最近满足条件的数字7的末点信息
//若满足条件，结果++，并且更新对应 最近满足条件的数字7的末点信息

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct frac{
	ll x, y;
	friend bool operator < (frac a, frac b) {
		return a.y * b.x < b.y * a.x;//根据斜率从小到大排序
	}
	// 重载 <=，用于计算结果中的判断操作
	friend bool operator <= (frac a, frac b) {
		return a.y * b.x <= b.y * a.x;
	}
};
int main() {
	int n;
	cin >> n;
	vector<pair<frac, frac>> data;		//fi为末点（左边点），se为起点（下方点）
	for(int i = 1;i <= n;i++) {
		int x, y;
		cin >> x >> y;
		data.push_back({{x-1, y}, {x, y-1}});
	}
	sort(data.begin(), data.end());		//先根据末点排序，然后根据起点排序
	frac now = {1, 0};					//初始化起点为斜率为0的点
	int ans = 0;
	for(int i = 0;i < data.size();i++) {//遍历所有数字7
		// 如果当前数字7的起点 斜率 大于等于 当前满足条件的边界斜率（满足条件的末点斜率）
		if(now <= data[i].se) {
			ans++;
			now = data[i].fi;			//更新对应的边界斜率（满足条件的末点斜率）
		}
	}
	cout << ans;
    return 0;
}
