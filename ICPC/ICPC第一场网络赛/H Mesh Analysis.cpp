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
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
using namespace std;
const int MAXN = 1e4+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct node{
	int u,id;
};
vector<node> g[MAXN];
map<int,int> mp, rev;//mp记录转换后的值，rev为转换前的值
int main() {
	int n, m, k;
	cin>>n>>m;
	for(int i = 1;i <= n;i++) {
		int id;
		double x, y, z;
		cin>>id>>x>>y>>z;
	}
	int cnt = 0;
	for(int i = 1;i <= m;i++) {
		int id, op, x, y, z;
		cin>>id>>op>>x>>y;//x, y, z的范围不确定，所以先转换，后计算
		if(mp.find(x)==mp.end()) mp[x] = cnt++, rev[cnt-1] = x;
		if(mp.find(y)==mp.end()) mp[y] = cnt++, rev[cnt-1] = y;
		x = mp[x], y = mp[y];//修改为转换后的值
		if(op==203) {
			cin>>z;
			if(mp.find(z)==mp.end()) mp[z] = cnt++, rev[cnt-1] = z;
			z = mp[z];//修改为转换后的值
			g[x].push_back({y, i});
			g[x].push_back({z, i});
			g[y].push_back({x, i});
			g[y].push_back({z, i});
			g[z].push_back({x, i});
			g[z].push_back({y, i});
		}
		else {
			g[x].push_back({y, i});
			g[y].push_back({x, i});
		}
	}
	cin>>k;
	while(k--) {
		int q;
		cin>>q;
		cout<<q<<"\n";
		if(mp.find(q)==mp.end()) {//先查询q是否有转换过，没有即为空
			cout<<"[]\n[]\n";
			continue;
		}
		q = mp[q];//无需再判断g[q]！！！
		vector<int> dot, ids;//dot记录点，ids记录对应的线段或三角形的id
		for(auto v: g[q]) {
			dot.push_back(v.u);
			ids.push_back(v.id);
		}
		sort(dot.begin(), dot.end());
		sort(ids.begin(), ids.end());
		auto pos = unique(dot.begin(), dot.end()) - dot.begin();
		auto pos1 = unique(ids.begin(), ids.end()) - ids.begin();
		cout<<"[";
		for(int i = 0;i < pos;i++) {
			if(i) cout<<",";
			cout<<rev[dot[i]];
		}
		cout<<"]\n[";
		for(int i = 0;i < pos1;i++) {
			if(i) cout<<",";
			cout<<ids[i];
		}
		cout<<"]\n";
	}
    return 0;
}
