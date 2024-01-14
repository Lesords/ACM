// Problem: C - Doukasen
// Contest: AtCoder - AtCoder Beginner Contest 223
// URL: https://atcoder.jp/contests/abc223/tasks/abc223_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-17 20:18:17

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
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
double a[MAXN], b[MAXN], tim[MAXN];
int main() {
	int n;
	cin >> n;
	double sum = 0;
	for(int i = 1;i <= n;i++) {
		cin >> a[i] >> b[i];
		tim[i] = a[i]/b[i];
		sum += tim[i];
	}
	sum /= 2;//中间时长即为相会位置
	double dis = 0, tmp = 0;
	for(int i = 1;i <= n;i++) {
		if(tmp+tim[i] <= sum) {
			tmp += tim[i];
			dis += a[i];
		}
		else {
			dis += (sum-tmp)/tim[i] * a[i];
			break;
		}
	}
	printf("%.7f", dis);
    return 0;
}
