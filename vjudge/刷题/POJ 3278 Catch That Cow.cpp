#include<iostream>//ac
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int pos,step;
	friend bool operator < (node a,node b) {
		//步数为少，距离最远
		if(a.step!=b.step) return a.step > b.step;
		else return a.pos < b.pos;
	}
};
const int MAXN = 200005;//两倍范围，因为有*2操作
int n,k;
int vis[MAXN];
void bfs() {
	priority_queue<node> q;
	q.push(node{n,0});//起点
	node tmp;
	while(!q.empty()) {
		tmp = q.top(),q.pop();
		if(tmp.pos==k) {//到达目的点
			printf("%d",tmp.step);
			return;
		}
		for(int i = -1;i <= 1;i+=2) {//正负两个操作
			int tx = tmp.pos+i;
			if(tx<0||vis[tx]) continue;
			//tx不能为负，也不能重复访问
			vis[tx] = tmp.step+1;//记录为步数
			q.push(node{tx,tmp.step+1});
		}
		if(tmp.pos>k||vis[tmp.pos*2]) continue;
		//超过k或已访问都需要跳过
		q.push(node{tmp.pos*2,tmp.step+1});
		vis[tmp.pos*2] = tmp.step+1;
	}
}
int main() {
	scanf("%d%d",&n,&k);
	if(n>=k) printf("%d",n-k);//超过k时，只能一步步走
	else bfs();
	return 0;
}
