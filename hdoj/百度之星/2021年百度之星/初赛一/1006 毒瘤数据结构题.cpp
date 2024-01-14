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
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define lowbit(x) (x)&(-x)
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 5e6+5;
const int MOD = 1e9+7;

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

int n,tree[MAXN],a[MAXN];
void add(int pos,int val) {
    if(a[pos]) return;
    while(pos<=n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
int ask(int pos) {
    int ans = 0;
    while(pos>=1) {
        ans += tree[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main() {
    re(n);
//    cin>>n;
    for(int i = 1;i <= n;i++) {
        int op,val;
        re(op),re(val);
//        cin>>op>>val;
        if(op==1) {
            if(a[val]==0) add(val, 1);
            a[val] = 1;
        }
        else {
            int flag = a[val];
            if(flag==0) add(val, 1);
            int l = 1,r = n,ans = 0;
            while(l<=r) {
                int mid = (l+r)/2;
                if(ask(mid)==mid) {
                    ans = mid;
                    l = mid+1;
                }
                else r = mid-1;
            }
            cout<<ans+1<<"\n";
            if(flag==0) add(val, -1);
        }
    }
	return 0;
}
