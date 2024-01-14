#include <stdio.h> // ac
#include <algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;

// 题意：有n个储藏柜，其中有m个柜子里有邮件，起点在1号柜子，钥匙都在k号柜子，
// 并且每次只能取一个柜子的钥匙，当取完所有邮件后需要返回起点，求最短路径
// 题解：由于刚开始的时候没有钥匙，所以需要从起点到达 k 号柜子，距离为 k - 1
// 接下来每次只能打开一个柜子，说明每开启一个柜子之后都需要返回 k 位置，所以距离为 abs(now - k) * 2 （now为当前位置柜子）
// 因为最后需要返回起点，所以在取完最后一个柜子之后可以不需要返回 k 位置，直接返回起点即可，也就是说只需要增加 now - 1
// 并且题目要求这个路径最小，所以可以使 离起点最近的柜子 最后取，这样所需要返回起点的值即为最小

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
    	int n, m, k, tmp, minn = INF;
    	scanf("%d%d%d", &n, &m, &k);
    	ll ans = k - 1;	// 第一次到达 k 位置的值
    	for (int i = 1; i <= m; ++i) {
    		scanf("%d", &tmp);
    		minn = min(minn, tmp);		// 更新离起点最近的位置
    		ans += llabs(tmp - k) * 2;	// 从 k 位置 到达 tmp 并且返回到 k 位置
    	}
    	ans -= llabs(k - minn);			// 扣除一次 最近位置 到达 k 的值 (即最后一次无需返回到 k 位置)
    	ans += minn - 1;				// 添加返回起点的值即可
    	printf("%lld\n", ans);
    }
    return 0;
}
