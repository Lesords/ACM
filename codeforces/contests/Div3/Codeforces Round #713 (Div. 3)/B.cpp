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
#define fi first
#define se second
using namespace std;
const int MAXN = 405;
char s[MAXN][MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int ax = 0,ay = 0,bx = 0,by = 0,flag = 0;
        for(int i = 1;i <= n;i++) cin>>s[i]+1;
        for(int i = 1;i <= n && !flag;i++) {
            for(int j = 1;j <= n && !flag;j++) {
                if(s[i][j]=='*') {
                    if(!ax&&!ay) {
                        ax = i, ay = j;
                    }
                    else {
                        bx = i, by = j;
                        flag = 1;
                    }
                }
            }
        }
        if(ax==bx) {
            int dis = 1;
            if(ax+dis<=n&&bx+dis<=n) s[ax+dis][ay] = s[bx+dis][by] = '*';
            else s[ax-dis][ay] = s[bx-dis][by] = '*';
        }
        else if(ay==by) {
            int dis = 1;
            if(ay+dis<=n&&by+dis<=n) s[ax][ay+dis] = s[bx][by+dis] = '*';
            else s[ax][ay-dis] = s[bx][by-dis] = '*';
        }
        else {
            s[ax][by] = s[bx][ay] = '*';
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                cout<<s[i][j];
            }
            cout<<"\n";
        }
    }
	return 0;
}
