// Problem: B - Mongeness
// Contest: AtCoder - AtCoder Beginner Contest 224
// URL: https://atcoder.jp/contests/abc224/tasks/abc224_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-23 20:02:05

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
const int MAXN = 60;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int a[MAXN][MAXN];
int main() {
	int h, w;
	cin >> h >> w;
	for(int i = 1;i <= h;i++) {
		for(int j = 1;j <= w;j++) {
			cin >> a[i][j];
		}
	}
	for(int i = 1;i <= h;i++) {
		for(int i2 = i+1;i2 <= h;i2++) {
			for(int j = 1;j <= w;j++) {
				for(int jj = j+1;jj <= w;jj++) {
					if(a[i][j]+a[i2][jj] > a[i2][j] + a[i][jj]) {
						cout << "No";
						return 0;
					}
				}
			}
		}
	}
	cout << "Yes\n";
    return 0;
}
