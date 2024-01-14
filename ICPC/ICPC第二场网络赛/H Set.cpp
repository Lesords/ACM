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

//题解：随机化k个长度为 ceil(512.0/r) 的区间即可

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
bool vis[300];
int main() {
	int k, r;
	cin>>k>>r;
	int len = ceil(512.0/r);//对应区间长度
	while(k--) {
		for(int i = 1;i <= 256;i++) vis[i] = 0;//清空所有位置
		int cnt = 0;//表示当前已经选择了的数量
		while(cnt<len) {
			int num = rand()%256+1;//范围为0~255，所以需+1
			if(vis[num]) continue;//如果当前这个数已经选过了，那么跳过
			vis[num] = 1;//否则标记
			cnt++;//并且数量++
		}
		for(int i = 1;i <= 256;i++) cout<<vis[i];
		cout<<"\n";
	}
    return 0;
}
