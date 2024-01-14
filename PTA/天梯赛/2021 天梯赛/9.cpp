#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<stack>
#include<string>
#include<queue>
#include<utility>
#include<algorithm>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 1e4+5;
queue<char> sq[105];
vector<char> ans;
stack<char> st;
int main() {
    int n,m,s;
    cin>>n>>m>>s;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            char ch;
            cin>>ch;
            sq[i].push(ch);
        }
    }
    int op;
    while(cin>>op) {
        if(op==-1) break;
        if(op==0) {
            if(st.empty()) continue;
            ans.push_back(st.top());
            st.pop();
        }
        else {
            if(sq[op].empty()) continue;//Ï¸½Ú
            if(st.size()==s) {
                ans.push_back(st.top());
                st.pop();
            }
            st.push(sq[op].front());
            sq[op].pop();
        }
    }
    for(int i = 0;i < ans.size();i++) {
        cout<<ans[i];
    }
    return 0;
}
