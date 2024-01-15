#include<iostream>//ac
#include<cmath>
#include<queue>
using namespace std;
int m,n,k;
struct node {
	int x,y,num;
	friend bool operator < (node a,node b) {
		return a.num < b.num;//优先找多的花生
	}
};
int main() {
	cin>>m>>n>>k;
	int tmp,ans = 0,time = 0,tx,ty;//结果和时间都初始化为0
	priority_queue<node> q;
	for(int i = 1;i <= m;i++) {
		for(int j = 1;j <= n;j++) {
			cin>>tmp;
			if(tmp) q.push(node{i,j,tmp});
		}
	}
	node tri;
	//防止出现有时间而没有花生的情况！！！
	while(!q.empty()) {//需要判断是否还有花生！
		tri = q.top();q.pop();
		if(!time) {//第一次找花生 
			tx = tri.x,ty = tri.y,time = tx+1;//设置花生位置和时间
			if(time+tri.x<=k) ans = tri.num;//有时间回去更新答案
			else break;//没有就退出
		}
		else {//移动时间 + 采花生的时间
			time += (abs(tri.x-tx)+abs(tri.y-ty))+1;
			tx = tri.x,ty = tri.y;//更新上一个花生位置
			if(time+tri.x<=k) ans += tri.num;//有时间回去更新答案
			else break;//没有就退出
		}
	}
	cout<<ans<<endl;
	return 0;
}
