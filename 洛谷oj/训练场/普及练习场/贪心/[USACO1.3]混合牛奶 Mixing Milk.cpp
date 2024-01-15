#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
struct node {
	int price,num;
	friend bool operator < (node a, node b) {//升序
		return a.price > b.price;//价格低的优先
	}
};
int main() {
	int n,m,ans = 0,num = 0;
	cin>>n>>m;
	node tmp;
	priority_queue<node> q;//升序优先队列
	for(int i = 1;i <= m;i++) {
		cin>>tmp.price>>tmp.num;
		q.push(tmp);
	}
	while(num<n) {
		tmp = q.top();q.pop();
		//只需要判断当前的牛奶量和所需牛奶量大小
		//然后实时更新 总价钱 和 当前牛奶总量
		if(n-num>=tmp.num) ans += tmp.num*tmp.price,num += tmp.num;
		else ans += (n-num)*tmp.price, num = n;//牛奶量够了
	}
	cout<<ans<<endl;
	return 0;
}
