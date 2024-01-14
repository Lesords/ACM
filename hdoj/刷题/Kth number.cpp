#include<iostream>//tle
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 1e5+5;
int a[maxn];
struct node {
	int x;
	friend bool operator < (node a,node b) {
		return a.x>b.x;
	}
};
int main() {
	int T,n,m,s,t,k;
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) {
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=m;i++) {
			cin>>s>>t>>k;
			priority_queue<node> q;
			for(int i=s;i<=t;i++) {
				q.push(node{a[i]});
				if(q.size()>k) q.pop();
			}
			cout<<q.top().x<<endl;
		}
	}
	return 0;
}
