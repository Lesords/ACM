// Problem: C - Shapes
// Contest: AtCoder - AtCoder Beginner Contest 218
// URL: https://atcoder.jp/contests/abc218/tasks/abc218_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-09-11 20:04:08

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

//题解：模拟
//每次将矩阵移动90度，然后记录左上角的坐标
//记录所有#格子的坐标，扣除左上角的坐标值（以左上角坐标为基准）
//然后判断两个矩阵的#格子坐标是否相等，相等即满足条件，否则不满足条件

const int MAXN = 200+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
char s[MAXN][MAXN], t[MAXN][MAXN], c[MAXN][MAXN];//s为第一个矩阵，t为第二个，c为操作矩阵
int n;
void rotate() {//矩阵t旋转90度
	for(int i = 1,ii = 1;i <= n;i++,ii++) {
		for(int j = 1,jj = n;j <= n;j++,jj--) {
			c[i][j] = t[jj][ii];
		}
	}
	for(int i = 1;i <= n;i++) {//将旋转后的结果复制到数组c中
		for(int j = 1;j <= n;j++) t[i][j] = c[i][j];
	}
}
pii get_pos(char s[][MAXN]) {//获取矩阵s的左上角坐标
	for(int i  = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(s[i][j]=='#') {
				return {i,j};
			}
		}
	}
}
vector<pii> get_list(char s[][MAXN], pii pos) {//获矩阵s的所有#坐标
	vector<pii> ans;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(s[i][j]=='#') {
				//扣除左上角的坐标值（以左上角的标准）
				ans.push_back({i-pos.fi,j-pos.se});
			}
		}
	}
	return ans;
}
int main() {
	cin>>n;
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) cin>>s[i][j];
	}
	pii s_top = get_pos(s);
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) cin>>t[i][j];
	}
	bool ok = 0;
	for(int _ = 1;_ <= 4;_++) {//旋转4次
		rotate();
		pii t_top = get_pos(t);//获取旋转后的左上角坐标值
		vector<pii> aa = get_list(s, s_top);
		vector<pii> bb = get_list(t, t_top);
		if(aa.size()!=bb.size()) {//#出现数量不一致
			ok = 0;break;
		}
		bool flag = 1;
		for(int j = 0;j < aa.size();j++) {
			if(aa[j]!=bb[j]) {//只要有一个坐标不相同，即不匹配
				flag = 0;break;
			}
		}
		if(flag) {//flag为1表示成功匹配，直接结束
			ok = 1;break;
		}
	}	
	if(ok) cout<<"Yes\n";
	else cout<<"No\n";
    return 0;
}