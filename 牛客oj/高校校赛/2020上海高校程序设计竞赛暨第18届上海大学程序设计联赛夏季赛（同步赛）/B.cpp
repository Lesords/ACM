#include<iostream>//ac   longlong(waµã)
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int pos[MAXN];
string s;
int get_num(char ch) {
    if(ch=='C') return 13;
    if(ch=='H') return 1;
    if(ch=='O') return 17;
}
ll dfs(int l,int r) {
    ll ans = 0,tmp = 0;
    stack<ll> sta;
    for(int i = l;i <= r;i++) {
        if(s[i]>='A'&&s[i]<='Z') sta.push(get_num(s[i]));
        else if(s[i]>='0'&&s[i]<='9') {
            ll num = s[i]-'0',nn;
            while(s[i+1]>='0'&&s[i+1]<='9') {
                nn = s[++i]-'0';
                num = num*10+nn;
            }
            nn = sta.top();sta.pop();
            sta.push(nn*num);
        }
        else if(s[i]=='(') {
            sta.push(dfs(i+1,pos[i]-1));
            i = pos[i];
        }
    }
    while(!sta.empty()) {
        ans += sta.top();sta.pop();
    }
    return ans;
}
int main() {
    cin>>s;
    stack<int> sta;
    for(int i = 0;i < s.size();i++) {
        if(s[i]=='(') sta.push(i);
        else if(s[i]==')') {
            pos[sta.top()] = i;
            sta.pop();
        }
    }
    cout<<dfs(0,s.size()-1)<<endl;
	return 0;
}
