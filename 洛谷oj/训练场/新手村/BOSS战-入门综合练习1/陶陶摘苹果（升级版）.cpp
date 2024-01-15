#include<iostream>//ac
#include<queue>
using namespace std;
struct apple{
	int height,power;
	friend bool operator < (apple a,apple b) {
		return a.power>b.power;//从大到小排序，队末为最小
	}
};
int main() {
	int n,s,a,b,x,y;
	priority_queue<apple> q;
	cin>>n>>s>>a>>b;
	for(int i = 1;i <= n;i++) {
		cin>>x>>y;
		if(x>a+b) continue;//摘不到就跳过
		q.push({x,y});
	}
	int ans = 0;//初始数量为0
	while(s) {
		apple tmp = q.top();//队末数据
		q.pop();
		if(tmp.power>s) break;//能量不够
		ans++;
		s -= tmp.power;//更新当前剩余能量
	}
	cout<<ans<<endl;
	return 0;
}
