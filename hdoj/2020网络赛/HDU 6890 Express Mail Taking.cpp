#include<iostream>//AC
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
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e6+5;
ll a[MAXN];
struct down{
    ll val;
    friend bool operator < (down a,down b) {
        return a.val < b.val;
    }
};
struct up{
    ll val;
    friend bool operator < (up a,up b) {
        return a.val > b.val;
    }
};

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

int main() {
    int t;
    re(t);
    while(t--) {
        ll n,m,k;
        re(n),re(m),re(k);
        priority_queue<down> xiao;
        priority_queue<up> da;
        for(int i = 1;i <= m;i++) {
            re(a[i]);
            if(a[i]<k) xiao.push(down{a[i]});
            if(a[i]>k) da.push(up{a[i]});
        }
        ll ans = k-1;
        while(!da.empty()) {
            up tmp = da.top();
            ans += (tmp.val-k)*2ll;
            da.pop();
        }
        if(xiao.empty()) {
            ans += k-1;
            cout<<ans<<endl;
            continue;
        }
        while(!xiao.empty()) {
            down tmp = xiao.top();
            if(xiao.size()==1) ans += k-1;
            else ans += (k-tmp.val)*2ll;
            xiao.pop();
        }
        cout<<ans<<endl;
    }
	return 0;
}
