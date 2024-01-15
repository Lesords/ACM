#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN];
int main() {
	int n,m,ans = 0;
	priority_queue<int,vector<int>,greater<int> > q;
	//升序排列（先小）
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 1;i <= m;i++) {//m个水龙头
		q.push(a[i]);
	}//前面的接完了后面的同学跟上
	//相当于当前水龙头花的时间为两个之和
	while(m<=n) {//剩余的同学
		int tmp = q.top();//少的水龙头
		q.pop();
		q.push(tmp+a[++m]);//把下一个同学的水量加上
	}
	while(!q.empty()) {//m个水龙头中最长的时间即为结果
		ans = max(ans,q.top());
		q.pop();
	}
	cout<<ans;
	return 0;
}
