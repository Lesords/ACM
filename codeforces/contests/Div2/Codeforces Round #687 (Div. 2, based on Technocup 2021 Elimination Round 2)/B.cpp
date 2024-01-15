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
int a[MAXN],num[105];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        memset(num,0,sizeof(num));
        int maxnum = 0,val = 0;
        for(int i = 1;i <= n;i++) {
            cin>>a[i],num[a[i]]++;
            if(num[a[i]]>maxnum) {
                maxnum = num[a[i]];
                val = a[i];
            }
        }
        int ans = INF;
        for(int i = 1;i <= 100;i++) {
            //遍历所有颜色，然后计算每种颜色所需的步骤，取最小值
            if(num[i]==0) continue;//当前颜色没有出现，则跳过
            int tans = 0,pos = 1;
            for(int j = 1;j <= n;) {
                if(a[j]!=i) {
                    tans++;
                    j += k;
                }
                else j++;
            }
            ans = min(ans,tans);
        }
        cout<<ans<<"\n";
    }
	return 0;
}
