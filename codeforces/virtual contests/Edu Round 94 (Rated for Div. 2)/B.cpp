#include<iostream>
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
const int MAXN = 1e5+5;
int main() {
    int t;cin>>t;
    while(t--) {
        ll p,f,cnta,cntb,a,b;
        cin>>p>>f>>cnta>>cntb>>a>>b;
        if(a==b) {
            ll tmp = p/a+f/a;
            cout<<min(tmp,cnta+cntb)<<endl;
            continue;
        }
        ll minn,maxx,min_num,max_num,ans = 0;
        if(a>b) maxx = a,max_num = cnta,minn = b,min_num = cntb;
        else maxx = b,max_num = cntb,minn = a,min_num = cnta;
        ll minsiz = min(p/minn,min_num);
        ll rest = p-minsiz*minn;
        if(rest==0) {
            ans += minsiz;
            min_num -= minsiz;
            p -= minsiz-minn;
        }
        else {
            ll dis = maxx-minn;
            if(rest>dis) {
                ll tmp = min(max_num,rest/dis);
                minsiz -= min(minsiz,tmp);
                ans += minsiz;
                min_num -= minsiz;
                p -= minsiz*minn;
                ans += tmp;
                max_num -= tmp;
                p -= tmp*maxx;
            }
            else {
                ans += minsiz;
                min_num -= minsiz;
                p -= minsiz*minn;
            }
        }
        minsiz = min(f/minn,min_num);
        rest = f-minsiz*minn;
        if(rest==0) {
            ans += minsiz;
        }
        else {
            ll dis = maxx-minn;
            if(rest>dis) {
                ll tmp = min(rest/dis,max_num);
                minsiz -= min(minsiz,tmp);
                ans += minsiz;
                min_num -= minsiz;
                ans += tmp;
            }
            else {
                ans += minsiz;
            }
        }
        cout<<ans<<endl;
    }
	return 0;
}
