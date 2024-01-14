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
const int MAXN = 1e3;
const int MOD = 1e9+7;
int val[205];
int pre[205];
int deep,n,flag;
// vector<int> ord;
int ord[205];
void init() {
	for(int i = 1;i <= 160;i++) {
		val[i] = i*i;
		pre[i] = pre[i-1]+val[i];
	}
}
void dfs(int pos,int sum) {
	if(flag) return;
	if(pos==0) {
		if(sum==n) {
			flag = 1;
			cout<<deep<<"\n";
			for(int i = 1;i <= deep;i++) cout<<ord[i];
			cout<<"\n";
		}
		return ;
	}
	if(pos<0) return;
	if(sum<n&&sum+pre[pos]<n) return;
	if(sum>n&&sum-pre[pos]>n) return;
	ord[pos] = 1;
	dfs(pos-1, sum+val[pos]);
	if(sum+val[pos]<n) return;
	if(flag) return;
	ord[pos] = 0;
	dfs(pos-1, sum-val[pos]);
}
int main() {
	fast;
	init();
	int t;
	cin>>t;
	while(t--) {
	   	cin>>n;
	   	int pos = lower_bound(pre+1, pre+161, n)-pre;
        for(int i = pos-1;i <= 200;i++) {
    		deep = i;
    	 	flag = 0;
    		dfs(deep, 0);
    		if(flag) {
    			break;
    		}
    	}
    }
    return 0;
}
