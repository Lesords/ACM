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
int V[MAXN];
map<int, ll>S;
ll Sum(ll n)
{
    int m = (int)sqrt(n);
    int t = n / m;
    for(int i = 1;i <= m;i++)  V[i-1] = n / i;

    int cnt = 1;
    for(int i = t + m - 2;i >= m;i--)  V[i] = cnt++;


    for(int i = 0;i <= t+m-2;i++)  S[V[i]] = 1LL * V[i] * (V[i]+1) / 2 - 1;

    for(int p = 2;p <= m;p++)
    {
        if(S[p] > S[p-1])
        {
            ll sp = S[p-1];
            ll p2 = p *  p;
            for(int i = 0;i <= t+m-2;i++)
            {
                ll v = V[i];
                if(v < p2)  break;
                S[v] -= p*(S[v/p] - sp);
            }
        }
    }

    return S[n];
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,k;
        cin>>n>>k;
        cout<<Sum(n)%k<<endl;
    }
	return 0;
}
