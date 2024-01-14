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

//题解：构造+思维
//1. 首先，如果所有位置的值与其下标相等，那么无需交换，结果为0
//2. 其次，如果所有位置不同的值连起来的环长度只为2（当前位置连向 当前值的位置 ）
//3. 最后，如果所有位置不同的值连起来的环长度大于2，那么可以将对应的环拆成若干个长度为2的小环
//例如：
//对环  a -> b -> c -> d -> e -> a，进行 a,e 交换，进行 b (a+1),d (e-1) 交换
//最后再将所有环的长度等于2的位置互相交换即可

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int a[MAXN], n, vis[MAXN];
bool check() {//特判是否所有位置都与下标相等（即无需交换）
	for(int i = 1;i <= n;i++) {
		if(i!=a[i]) return false;
	}
	return true;
}
int main() {
	fast;
	cin >> n;
	for(int i = 1;i <= n;i++) cin >> a[i];
	if(check()) {//特判无需交换的情况
		cout << "0";
		return 0;
	}
	
	vector<int> ans[2];
	for(int i = 0;i < 2;i++) {
		memset(vis, 0, sizeof(vis));//清空所有标记
		for(int j = 1;j <= n;j++) {
			//如果当前位置已经被标记过（已交换过），那么跳过
			//如果当前位置的值和下标值一致（无需交换），那么跳过
			if(vis[j]||j==a[j]) continue;
			int t = a[j];				//a[j]的值 即为j位置要到达的位置
			vector<int> cyc;			//存储对应环的下标
			cyc.push_back(j);			//当前环的起点是j，下一个点的位置是t
			vis[j] = 1;					//标记
			while(t!=j) {
				cyc.push_back(t);		//记录对应位置
				vis[t] = 1;				//标记
				t = a[t];				//继续获取下一个位置
			}
			int siz = cyc.size();
			for(int k = 0;k < siz/2;k++) {//取环的一半
				// 从0和siz-1的位置开始，两两一起往下走
				int x = cyc[k], y = cyc[siz-1-k];
				ans[i].push_back(x);
				ans[i].push_back(y);
				swap(a[x], a[y]);		//记录完之后需要交换
			}
		}
	}
	if(ans[1].empty()) {//如果第二个位置都没有值，那么说明只需要一次交换
		cout << "1\n";
		cout << ans[0].size()/2;
		for(int i = 0;i < ans[0].size();i++) cout << " " << ans[0][i];
	}
	else {
		cout << "2\n";
		cout << ans[0].size()/2;
		for(int i = 0;i < ans[0].size();i++) cout << " " << ans[0][i];
		cout << "\n";
		cout << ans[1].size()/2;
		for(int i = 0;i < ans[1].size();i++) cout << " " << ans[1][i];
	}
    return 0;
}
