#include<iostream>//ac
#include<queue>
using namespace std;
int main() {
	int n,a,ans = 0;
	priority_queue<int, vector<int>, greater<int> >q;//升序队列
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a;
		q.push(a);
	}
	int tmp1, tmp2;
	while(!q.empty()) {//哈夫曼原理
		tmp1 = q.top();q.pop();
		if(!q.empty()) {//不为空时才有第二个量
			tmp2 = q.top();q.pop();
		}
		else tmp2 = 0;//否则为0
		ans += tmp1+tmp2;
		if(!q.empty()) q.push(tmp1+tmp2);//不为空时才需要入队
	}
	cout<<ans<<endl;
	return 0;
}
