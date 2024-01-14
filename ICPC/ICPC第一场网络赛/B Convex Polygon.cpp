#include<iostream>
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
const int MAXN = 1e3+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
struct Point{
	int x,y;
	friend bool operator < (Point a, Point b) {
		// return a.x
	}
}dot[MAXN];
int cnt = 1;
bool judge() {
	for(int i = 1;i < cnt;i++) {
		for(int j = i+1;j < cnt;j++) {
			
		}
	}
}
int main() {
	// string s;
	// getline(cin, s);
	// for(int i = 1;i < s.size();i++) {
		// if(s[i]==s[i-1]&&s[i]==',') {
			// cout<<"ERROR";
		// }
	// }
	// stringstream ss(s);
// 	
	// int tmp;
	// while(ss>>tmp) {
		// cout<<tmp<<"\n";
	// }
	// return 0;
	
	
	int a,b;
	scanf("%d,%d", &a, &b);
	dot[cnt++] = {a, b};
	cout<<a<<" "<<b<<"\n";
	while(scanf(",%d,%d",&a, &b)!=EOF) {
		dot[cnt++] = {a, b};
		cout<<a<<" "<<b<<"\n";
	}
	if(judge()) {
		cout<<"ERROR\n";
		return 0;
	}
	for(int i = 1;i < cnt;i++) {
		cout<<dot[i].x<<" "<<dot[i].y<<"\n";
	}
    return 0;
}
