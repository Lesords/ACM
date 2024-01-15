#include<iostream>//ac ¿ì¶ÁÄ£°å
#include<cstdio>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
const int MAXN = 2e7+10;
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
int a[MAXN];
int main() {
	int t,n,k;
	re(t);
	while(t--) {
		re(n),re(k);
		for(int i = 1;i <= n;++i) {
			re(a[i]);
		}
		sort(a+1,a+n+1);
		printf("%d\n",a[k]);
	}
	return 0;
}
