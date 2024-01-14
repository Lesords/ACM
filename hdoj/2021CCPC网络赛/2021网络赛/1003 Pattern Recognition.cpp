#include<iostream>
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
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
const int MOD = 1e9+7;
string s[MAXN];
vector<vector<int>> vis;
vector<char> path;
map<string,int> ans;
int n,m,q,num;
void dfs(int x,int y) {
		
}
int main() {
    int t;
    cin>>t;
    while(t--) {
    	int n,m,q;
    	cin>>n>>m>>q;
    	ans.clear();
    	path.clear();
    	vis.resize(n);
    	for(int i = 0;i < n;i++) {
    		cin>>s[i];
    		vis[i].resize(m);
    	}
    	for(int i = 0;i < n;i++) {
    		for(int j = 0;j < m;j++) {
    			cout<<vis[i][j]<<" ";
    		}
    		cout<<"\n";
    	}
    	for(int i = 0;i < n;i++) {
    		for(int j = 0;j < m;j++) {
    			if(vis[i][j]==0) {
    				dfs(i, j);
    			}
    		}
    	}
    	while(q--) {
    		string s;
    		cin>>s;
    		cout<<ans[s]<<"\n";
    	}
    }
    return 0;
}