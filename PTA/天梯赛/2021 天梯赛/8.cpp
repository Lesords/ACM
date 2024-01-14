#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int MAXN = 1e4+5;
vector<ll> ans;
int main() {
    ll a,b,n;
    cin>>a>>b>>n;
    ans.push_back(a);
    ans.push_back(b);
    for(int i = 0;i < n;i++) {
        if(ans.size()>=n) break;
        ll tmp1 = ans[i];
        ll tmp2 = ans[i+1];
        ll val = tmp1*tmp2;
        if(val==0) {
            ans.push_back(val);
            continue;
        }
        stack<int> st;
        while(val) {
            st.push(val%10);
            val /= 10;
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
            if(ans.size()>=n) break;
        }
    }
    for(int i = 0;i < n;i++) {
        if(i!=0) cout<<" ";
        cout<<ans[i];
    }
    return 0;
}
