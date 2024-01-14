#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e6+6;
int val[MAXN][11];
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
    for(int i = 1;i < MAXN;i++) {
        for(int j = 2;j <= 10;j++) {
            int tmp = i;
            while(tmp) {
                val[i][j] += tmp%j;
                tmp /= j;
            }
            val[i][j] += val[i-1][j];
        }
    }
    int t;
    scanf("%d",&t);//快读和scanf都可过
//    re(t);
    for(int i = 1;i <= t;i++) {
        int ans = 0,n,b;
//        re(n),re(b);
        scanf("%d%d",&n,&b);
        printf("Case #%d: %d\n",i,val[n][b]);
    }
    return 0;
}
