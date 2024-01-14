#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<algorithm>
#define ll long long
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAXN = 2e6+5;
const int MOD = 998244353;
inline char gcd() {
	static char buf[100010], *h = buf, *t = buf;
	return h == t && (t = (h=buf) + fread(buf, 1, 100000, stdin), h == t) ? EOF: *h++;
}
template<class T>
inline void re(T &x) {
	x = 0;
	char a; bool b = 0;
	while(!isdigit(a = gcd())) b = a == '-';
	while(isdigit(a)) {
		x = (x << 1) + (x << 3) + a - '0', a = gcd();
	}
	if (b== 1) x *= -1;
}
ll a[MAXN], n, m, dis[MAXN], num[MAXN];
struct node{
	int pos, val;
	friend bool operator < (node a,node b){
		return a.val > b.val;
	}
};
int main() {
	re(n), re(m);
	for(int i = 1;i <= m;i++) {
		re(a[i]);
		num[i] = 1;
	}
	for(int i = 1;i < m;i++) dis[i] = a[i+1] - a[i]-1;
	
	dis[m] = n-a[m] + (a[1]-1);	
	priority_queue<node> q;
	for(int i = 1;i <= m;i++) q.push({i, dis[i]});
	
	while(!q.empty()) {
		node tmp = q.top();q.pop();
		int i = tmp.pos;
		int nxt = i+1;
		if(nxt==m+1) nxt = 1;
		ll dd = tmp.val;
		ll val = dd/2;
		if(dd%2) {
			if(num[i]+val+1 <= num[nxt]+val) {
				num[i] += val+1;
				num[nxt] += val;
			}
			else {
				num[i] +=val;
				num[nxt] += val+1;
			}
		}
		else {
			num[i] += val;
			num[nxt] += val;
		}
	}
	
	// for(int i = 1;i <= m;i++) {
		// int nxt = i+1;
		// if(i==m) nxt = 1;
		// if(dis[i]%2) {
			// ll val = dis[i]/2;
			// if(num[i]+val+1 <= num[nxt]+val) {
				// num[i] += dis[i]/2+1;
				// num[nxt] += dis[i]/2;
			// }
			// else {
				// num[i] += dis[i]/2;
				// num[nxt] += dis[i]/2+1;
			// }
		// }
		// else {
			// num[i] += dis[i]/2;
			// num[nxt] += dis[i]/2;
		// }
	// }
// 	
	
	ll ans = 0;
	for(int i = 1;i <= m;i++) ans = max(ans, num[i]), cout << num[i] << " ";
	cout << "\n";
	cout << ans;
	return 0;
}