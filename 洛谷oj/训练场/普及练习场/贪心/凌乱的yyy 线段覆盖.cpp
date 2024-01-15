#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int s,e;
	friend bool operator < (node a,node b) {//区间尽量更小
		if(a.e!=b.e) return a.e > b.e;//结束时间从小到大
		return a.s < b.s;//开始时间从大到小
	}
};
int main() {
	int n,a,b,ans = 0;
	priority_queue<node> q;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a>>b;
		q.push(node{a,b});
	}
	node tmp;
	int start = 0;//start表示当前时间
	while(!q.empty()) {
		tmp = q.top();q.pop();
		//当前节目开始时间大于start时
		//结果++并更新start时间为 当前节目结束的时间
		if(tmp.s>=start) ans++,start = tmp.e;
	}
	cout<<ans;
	return 0;
}
