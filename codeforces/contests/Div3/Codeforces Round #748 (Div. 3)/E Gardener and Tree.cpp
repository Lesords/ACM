// Problem: E. Gardener and Tree
// Contest: Codeforces - Codeforces Round #748 (Div. 3)
// URL: https://codeforces.ml/contest/1593/problem/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Author：Lese
// Time：2021-10-13 23:40:13

#include<iostream>//ac
#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
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
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
#define lson rt<<1
#define rson rt<<1|1
using namespace std;

//题解：类似于拓扑排序，从入度为1的所有点开始遍历，对应指向点的入度--
//若指向点的入度也为1，则入队
//注意：每次删除叶子节点的操作是固定的，也就是说，需要提前判断队列中的叶子个数！！！

const int MAXN = 4e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));
int in[MAXN];
vector<int> g[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
    	int n, k;
    	cin >> n >> k;
    	for(int i = 1;i <= n;i++) in[i] = 0, g[i].clear();
    	for(int i = 1;i < n;i++) {
    		int u, v;
    		cin >> u >> v;
    		g[u].push_back(v);
    		g[v].push_back(u);
    		in[u]++, in[v]++;
    	}
    	if(n<=2) {
    		cout << "0\n";
    		continue;
    	}
    	set<int> st;
    	queue<int> q;
    	for(int i = 1;i <= n;i++) {
    		if(in[i]==1) q.push(i);
    	}
    	for(int i = 1;i <= k;i++) {
    		if(q.empty()) break;
    		int siz = q.size();//当前队列中的叶子个数
    		for(int j = 1;j <= siz;j++) {
    			int dot = q.front();
    			q.pop();
    			st.insert(dot);
    			for(auto v:g[dot]) {
    				if(st.count(v)) continue;
    				in[v]--;
    				if(in[v]==1) {
    					q.push(v);
    				}
    			}
    		}
    	}
    	cout << n - st.size() << "\n";
    }
    return 0;
}
