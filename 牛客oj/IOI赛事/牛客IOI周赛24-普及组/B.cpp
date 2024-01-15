#include<iostream>//tle
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
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
string l,r,s;
int slen;
ll C(ll a,int num) {
    ll ans = 0;
    for(int i = num;i >= 1;i--) {
        ans += a-i+1;
    }
    return ans;
}
ll solve(string val,bool cont) {
    int len = val.size();
    ll ans = C(slen,len-1);
    for(int i = len-1;i < slen;i++) {
        string tmp = "";
        for(int j = i-len+1;j <= i;j++) {
            tmp += s[j];
        }
        int cnt = 0,pos = i-len+1;
        while(pos-1>=0&&s[pos-1]=='0') cnt++,pos--;
        while(tmp.size()>1&&tmp[0]=='0') tmp.erase(0,1);
        if(cont&&tmp==val) ans += cnt+1;
        else if(tmp<val&&tmp.size()==val.size()) ans += cnt+1;
        else if(tmp.size()<val.size()) ans += cnt+1;
    }
    return ans;
}
int main() {
    cin>>l>>r>>s;
    slen = s.size();
    cout<<solve(r,1)-solve(l,0)<<"\n";
	return 0;
}
