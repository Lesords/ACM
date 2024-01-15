#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：直接暴力即可

const int MAXN = 105;
int a[MAXN],b[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,sum = 0;
        cin>>n;
        vector<int> Plus,Minus;
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i <= n;i++) {
            int tmp;
            cin>>tmp;
            b[i] = a[i]-tmp;
            if(b[i]>0) Plus.push_back(i);
            else if(b[i]<0) Minus.push_back(i);
            sum += b[i];
        }
        if(sum) {
            cout<<"-1\n";
            continue;
        }
        vector<pii> ans;
        for(auto i:Plus) {
            while(b[i]!=0) {
                for(auto j:Minus) {
                    if(b[j]==0) continue;
                    ans.push_back({i,j});
                    b[i] -= 1;
                    b[j] += 1;
                    break;
                }
            }
        }
        cout<<ans.size()<<"\n";
        for(auto val:ans) {
            cout<<val.fi<<" "<<val.se<<"\n";
        }
    }
	return 0;
}

