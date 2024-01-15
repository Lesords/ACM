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
bool vis[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        memset(vis,0,sizeof(vis));
        string s;
        int x,flag = 0;
        cin>>s>>x;
        for(int i = 0;i < s.size();i++) {
            if(s[i]=='0') {
                //两边都越界的话也成立！！！
                if(i-x>=0) vis[i-x] = 1;
                if(i+x<s.size()) vis[i+x] = 1;
            }
        }//先构造再判断合法性！！！
        for(int i = 0;i < s.size();i++) {
            int tmp = 0;
            if(s[i]=='0') continue;
            if(i-x>=0&&vis[i-x]==0) tmp = 1;
            if(i+x<s.size()&&vis[i+x]==0) tmp = 1;
            if(tmp==0) {
                flag = 1;break;
            }
        }
        if(flag) {
            cout<<"-1\n";continue;
        }
        for(int i = 0;i < s.size();i++) {
            if(vis[i]) cout<<'0';
            else cout<<'1';
        }
        cout<<endl;
    }
	return 0;
}
