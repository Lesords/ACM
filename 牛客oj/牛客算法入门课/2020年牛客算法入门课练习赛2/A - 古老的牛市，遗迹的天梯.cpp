#include<iostream>//wa
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 205;
int h[MAXN],vis[MAXN],n;
struct node{
	int pos,step,back;
	friend bool operator < (node a,node b) {
		if(a.step!=b.step) return a.step > b.step;
		if(a.pos!=b.pos) return a.pos < b.pos;
		return a.back > b.back;
	}
};
int bfs(int pos,int step,int back) {
	priority_queue<node> q;
	q.push(node{pos,step,back});
	node tmp;
	while(!q.empty()) {
		tmp = q.top();q.pop();
		if(tmp.pos==n) return tmp.step;
		cout<<tmp.pos<<endl;
		int dis = h[tmp.pos+1]-h[tmp.pos];
		if(dis==1) {
			if(!vis[tmp.pos+1]) {
				q.push(node{tmp.pos+1,tmp.step+1,0});
			}
		}
		else {
			if(tmp.pos>1)
				q.push(node{tmp.pos-1,tmp.step+1,tmp.step-1});
		}
		if(tmp.back<0) {
			int hei = h[tmp.pos] + (2<<(-tmp.back));
			int index;
			for(int i = tmp.pos+1;i <= n;i++) {
				if(h[i]>hei) {
					index = i-1;break;
				}
			}
			if(vis[index]) continue;
			vis[index] = 1;
			q.push(node{index,tmp.step+1,0});
		}
	}
}
int main() {
	int flag = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>h[i];
		if(i>1&&(2<<(i-1)+h[1])<h[i]) {
			flag = 1;
		}
	}
	if(flag) cout<<"-1";
	else cout<<bfs(1,0,0);
	return 0;
}
