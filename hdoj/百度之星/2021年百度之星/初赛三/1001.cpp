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
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-5
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
int a[4];
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,maxx,minn,ave;
        scanf("%d%d%d%d", &n,&maxx,&minn,&ave);
        if(maxx<minn) {//有数据错的情况！！！
            cout<<"no\n";
            continue;
        }
        if(n==1) {
            int ans = (maxx==minn)&&(minn==ave);
            if(ans) printf("yes\n");
            else printf("no\n");
        }
        else if(n==2) {
            if(maxx+minn==ave*2) printf("yes\n");
            else printf("no\n");
        }
        else {
            double sum = ave*n;
            sum -= maxx+minn;
            sum /= n-2;
            if(sum>=minn&&sum<=maxx) printf("yes\n");
            else printf("no\n");
        }
    }
	return 0;
}
