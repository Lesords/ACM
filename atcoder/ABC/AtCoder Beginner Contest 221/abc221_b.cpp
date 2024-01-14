// Problem: B - typo
// Contest: AtCoder - AtCoder Beginner Contest 221
// URL: https://atcoder.jp/contests/abc221/tasks/abc221_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-02 20:00:51

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

//题意：两个字符串，对其中进行一次（或零次）交换操作（交换相邻两个字符）
//判断两个字符串是否有可能相等
//题解：记录所有不相等的位置，如果数量为空，满足条件
//如果数量为2，需要判断这两个位置是否相邻，并且对应位置的字符是否相等（交换后）
//若为其他数量，不符合条件

//官方做法：遍历所有位置，如果找到不相等的位置，判断交换后是否相等（前两个，后两个）
//如果有一次满足条件即可（注意，记得还原）

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int main() {
	string s,t ;
	cin>>s>>t;
	int num = 0, judge = 0;
	vector<int> ord;
	for(int i = 0;i < s.size();i++) {
		if(s[i]!=t[i]) {
			ord.push_back(i);//记录不相等的位置
		}
	}
	if(ord.empty()) cout<<"Yes\n";//为空，满足条件
	else {
		if(ord.size()==2) {//为两个
			int pos1 = ord[0], pos2 = ord[1];
			if(ord[0]+1!=ord[1]) cout<<"No\n";//两个位置必须相邻，否则不满足条件
			else {
				//交换后的字符需要相等，才满足条件
				if(s[pos1]==t[pos2]&&s[pos2]==t[pos1]) cout<<"Yes\n";
				else cout<<"No\n";
			}
		}
		else cout<<"No\n";//其他数量，不满足条件
	}
    return 0;
}
