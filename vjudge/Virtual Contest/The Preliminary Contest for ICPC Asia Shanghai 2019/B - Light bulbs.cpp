#include<iostream>//ac 快读不是正解
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1e6+6;
int a[MAXN];
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
    for(int i = 1;i <= t;i++) {
        int n,m;
        re(n),re(m);//只能快读
        for(int j = 1;j <= m;j++) {
            int x,y;
            re(x),re(y);
            a[x]++,a[y+1]--;
        }
        int ans = 0,sum = 0;
        for(int i = 0;i < n;i++) {
            sum += a[i];
            a[i] = 0;
            if(sum&1) ans++;
        }
        printf("Case #%d: %d\n",i,ans);
    }
    return 0;
}
