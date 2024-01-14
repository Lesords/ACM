#include<iostream>//ac
#include<cstdio>
#include<string>
#include<stack>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= k;i++) {
        for(int j = 1;j <= n;j++) {
            cin>>a[j];
        }
        stack<int> st;
        int pos = 1,flag = 0;
        for(int j = 1;j <= n;) {
            while(!st.empty()) {
                if(st.top()==j) {
                    st.pop();
                    j++;
                }
                else break;
            }
            if(a[pos]==j) {
                pos++,j++;
            }
            else {
                st.push(a[pos++]);
                if(st.size()>m) {
                    flag = 1;break;
                }
            }
        }
        if(!flag) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}
