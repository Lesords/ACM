// Problem: A - Seismic magnitude scales
// Contest: AtCoder - AtCoder Beginner Contest 221
// URL: https://atcoder.jp/contests/abc221/tasks/abc221_a
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-02 20:00:48

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

//题解：abs(a-b)个32相乘即可
//因为每增加1，结果需要*32

const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int main() {
	int a, b;
	int num = 32, ans = 1;
	cin>>a>>b;
	for(int i = 1;i <= abs(a-b);i++) {
		ans *= num;
	}
	cout<<ans;
    return 0;
}
