#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
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
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int x[MAXN], c[MAXN];
int a[MAXN], siz;
set<int> st;


inline char gch()
{
    static char buf[100010], *h = buf, *t = buf;
    return h == t && (t = (h = buf) + fread(buf, 1, 100000, stdin), h == t) ? EOF : *h ++;
}
template<class T>
inline void re(T &x)
{
    x = 0;
    char a; bool b = 0;
    while(!isdigit(a = gch()))
        b = a == '-';
    while(isdigit(a))
        x = (x << 1) + (x << 3) + a - '0', a = gch();
    if(b == 1)
        x *= -1;
}


int getP(int val) {
	return lower_bound(a+1, a+siz+1, val) - a;
}
int main() {
	int l,q;
	int num = 0;
	re(l), re(q);
	a[++num] = 0;
	for(int i = 1;i <= q;i++) {
		re(c[i]), re(x[i]);
		a[++num] = x[i];
	}
	a[++num] = l;
	sort(a+1, a+num+1);
	siz = unique(a+1, a+num+1) - a-1;
	// for(int i = 1;i <= siz;i++) cout<<a[i]<<" ";
	// cout<<"\n";
	// for(int i = 1;i <= q;i++) {
		// cout<<getP(x[i])<<"\n";
	// }
	
	st.insert(getP(0));
	st.insert(getP(l));
	for(int i = 1;i <= q;i++) {
		if(c[i]==1) {
			st.insert(getP(x[i]));
		}
		else {
			auto pos = st.lower_bound(getP(x[i]));//使用自带的二分函数！！！
			printf("%d\n", a[*pos]-a[*prev(pos)]);
			
		}
	}
    return 0;
}