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
        int n,ans = 0,ans2 = 0;
        string s;
        cin>>n>>s;
        for(int i = 1;i < s.size();i++) {
            if(s[i]==s[i-1]&&s[i]=='1') ans++;
        }
        for(int i = 1;i < s.size();i++) {
            if(s[i]==s[i-1]&&s[i]=='0') ans2++;
        }
        cout<<max(ans2,ans)<<endl;
    }
	return 0;
}
