// Problem: C - Swiss-System Tournament
// Contest: AtCoder - Exawizards Programming Contest 2021（AtCoder Beginner Contest 222）
// URL: https://atcoder.jp/contests/abc222/tasks/abc222_c
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Author：Lese
// Time：2021-10-09 20:00:45

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
char a[105][105];
struct node {
	int num, id;
	friend bool operator < (node a, node b) {
		if(a.num==b.num) return a.id < b.id;
		return a.num > b.num;
	}
}score[105];
int siz;
int main() {
	// G rock, C scissors, P paper
	int n, m;
	cin >> n >> m;
	siz = 2*n;
	for(int i = 1;i <= siz;i++) {
		for(int j = 1;j <= m;j++) {
			cin >> a[i][j];
		}
		score[i].id = i;
	}
	for(int i = 1;i <= m;i++) {
		// cout << "the " << i << " round:\n";
		// for(int i = 1;i <= siz;i++) {
			// cout << score[i].id << " " << score[i].num << "\n";
		// }
		// cout << "-----\n";
		for(int j = 1;j <= siz;j += 2) {
			int id1 = score[j].id, id2 = score[j+1].id;
			char one = a[id1][i], two = a[id2][i];
			if(one==two) continue;
			if(one=='G') {
				if(two=='C') score[j].num++;
				else score[j+1].num++;
			}
			else if(one == 'C') {
				if(two == 'P') score[j].num++;
				else score[j+1].num++;
			}
			else if(one == 'P'){
				if(two == 'G') score[j].num++;
				else score[j+1].num++;
			}
		}
		sort(score+1, score+siz+1);
	}	
	for(int i = 1;i <= siz;i++) {
		cout << score[i].id << "\n";
	}
    return 0;
}
