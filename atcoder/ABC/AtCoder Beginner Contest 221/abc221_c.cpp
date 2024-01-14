// Problem: C - Select Mul
// Contest: AtCoder - AtCoder Beginner Contest 221
// URL: https://atcoder.jp/contests/abc221/tasks/abc221_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-02 20:00:55

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
#define lson rt<<1
#define rson rt<<1|1
using namespace std;

//题意：对应一个数字，进行数位全排列，然后分割成两个数字（不能有前导零），求两数最大乘积
//题解：由于数位最多只有9位，所以枚举所有的结果不是很大（可以分割成两部分，一个确定了，另外就是剩余部分）
//然后再计算两个数字的值，取较大值即可

//官方题解：所有位置全排列，所有分割成两个部分，利用字符串来存储对应的数值
//跳过包含前导零的情况，然后用stoi函数转成十进制数值，取最大值即可
//stoi可以将字符串转成十进制数值

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
vector<int> ord;//记录所有数位
int a[11], vis[11], siz;//a记录对应的数位位置，vis标记对应位置的值是否被选过，siz为遍历的数量
ll ans;
bool cmp(int a, int b) {//数位升序
	return a > b;
}
int solve(int flag) {//计算标记为flag的数值结果
	ll A = 0;
	for(int i = 0;i < ord.size();i++) {
		if(vis[i]==flag) {
			A = A*10 + ord[i];
		}
	}
	return A;
};
void dfs(int pos) {//dfs枚举所有位置（选择的可能性），pos为当前需要枚举的位置
	if(pos==siz+1) {//到达边界，那么分别计算两个值，取最大值
		ll A = solve(0), B = solve(1);
		ans = max(ans, A*B);
		return;
	}
	for(int i = 0;i < ord.size();i++) {//遍历所有位置！！！
		if(pos==1&&ord[i]==0) continue;//首位置，当时有0（前导零），跳过
		if(vis[i]) continue;//跳过已被选择的位置
		vis[i] = 1;//标记
		a[pos] = i;//记录对应位置选择的结果
		dfs(pos+1);
		vis[i] = 0;//取消标记
	}
}
int main() {
	int n;
	cin>>n;
	int tmp = n;
	int num = 0, cnt = 0;//num without zero
	while(tmp) {//分解原数据
		ord.push_back(tmp%10);
		tmp /= 10;
		cnt++;
	}
	sort(ord.begin(), ord.end(), cmp);//排序所有数位
	ll A = 0, B = 0;
	siz = ord.size()/2;//只需要枚举一般即可
	dfs(1);
	cout<<ans;
    return 0;
}
