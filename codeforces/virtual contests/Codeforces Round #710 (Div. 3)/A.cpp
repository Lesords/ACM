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
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
    int t;
    cin>>t;
    while(t--) {
        ll n,m,x;
        cin>>n>>m>>x;//题目中是按列排序的
        ll posy = ceil((double)x/n);
        ll posx = (x%n);
        if(posx==0) posx = n;
        cout<<((posx-1)*m)+posy<<"\n";//输出按行排序的
    }
	return 0;
}
