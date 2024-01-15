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
char ans[100];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        string s;
        cin>>n>>s;
        ans[1] = s[0];
        int pos = 1,cnt = 1;
        while(pos<=n&&cnt<n) {
            int tmp = cnt,flag = 0;
            for(int i = 1;i <= pos;i++) {
                if(s[tmp++]==ans[i]) {
                    flag = 1;break;
                }
            }
            if(flag) {
                cnt++;continue;
            }
            ans[pos+1] = s[cnt+pos];
            pos++;
        }
        while(pos+1<=n) ans[++pos] = '0';
        for(int i = 1;i <= n;i++) {
            cout<<ans[i];
        }
        cout<<endl;
        memset(ans,' ',sizeof(ans));
    }
	return 0;
}
