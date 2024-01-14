// Problem: Full Tank?
// Contest: Virtual Judge - POJ
// URL: https://vjudge.net/problem/POJ-3635
// Memory Limit: 65 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-10-12 10:33:46

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

//题解：优先队列bfs
//注意：POJ中G++才支持C11
//优先队列中维护 当前城市、剩余油量，总花费值 三个值
//队列中优先总花费值较小的
//到达每个城市都有两个操作：
//1. 加油，如果油箱还没满，并且花费值比原先小，则加油
//2. 移到下一个可到达的城市，如果油箱内的油够，并且到达下一城市的花费比之前小，则需移动

const int MAXN = 1e3+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	int v, val;//v为指向点，val为边权值
};
struct node2{
	int city, fuel, cost;
	friend bool operator < (node2 a, node2 b) {
		return a.cost > b.cost;//优先花费值小的！！！
	}
};
int n, m, q, p[MAXN];			//p为对应城市的油价
int num[MAXN][105];				//记录到达对应城市i，剩余油量为j的花费值
vector<node> g[MAXN];			//存边
int main() {
	fast;
	cin >> n >> m;
	for(int i = 1;i <= n;i++) cin >> p[i];
	for(int i = 1;i <= m;i++) {
		int u, v, w;
		cin >> u >> v >> w;
		u++, v++;//由于题目数据中起点从0开始，所以偏移一位，使其从1开始
		//注意是u和v，没有w！！！
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	cin >> q;
	while(q--) {
		priority_queue<node2> q;
		memset(num, 0x3f, sizeof(num));			//初始化为INF
		int s, t, c;
		cin >> c >> s >> t;
		s++, t++;								//偏移一位
		q.push({s, 0, 0});
		num[s][0] = 0;							//起点花费为0
		int flag = 0;							//标记是否能到达t位置
		while(!q.empty()) {
			int city = q.top().city;
			int fuel = q.top().fuel;
			int cost = q.top().cost;
			q.pop();
			if(city==t) {						//到达目的城市，直接输出花费值即可
				flag = 1;						//标记为可到达
				cout << cost << "\n";
				break;
			}
			//加油 油还没满，并且加油后花费值比原先少
			if(fuel < c && num[city][fuel+1] > cost+p[city]) {
				num[city][fuel+1] = cost + p[city];//更新为较小值
				q.push({city, fuel+1, num[city][fuel+1]});
			}
			//移到下一个可达的城市
			for(int i = 0;i < g[city].size();i++) {
				int dot = g[city][i].v;			//对应城市
				int val = g[city][i].val;		//到达该城市所需要花费的油量
				if(fuel >= val && num[dot][fuel-val] > cost) {
					//到达dot城市，剩余fuel-val油量的值为cost
					num[dot][fuel-val] = cost;
					q.push({dot, fuel-val, num[dot][fuel-val]});
				}
			}
		}
		//0表示无法到达
		if(!flag) cout << "impossible\n";
	}
    return 0;
}
