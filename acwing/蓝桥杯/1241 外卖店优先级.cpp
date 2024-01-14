#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
struct node{
	int tim,id;//tim为订单的时间，id为店的编号
	friend bool operator < (node a,node b) {
	    //先按时间从小到大排序，然后按照编号排序
		if(a.tim!=b.tim) return a.tim < b.tim;
		return a.id < b.id;
	}
}a[MAXN];//存储每个订单的信息
int level[MAXN],last[MAXN],pri[MAXN];//pri记录当前点是否在优先缓冲中
//level存储每个店的优先级，last记录每个店上一个编号的时间
int main() {
	int n,m,t;
	cin>>n>>m>>t;
	for(int i = 1;i <= m;i++) cin>>a[i].tim>>a[i].id;
	sort(a+1,a+m+1);//先排序
	for(int i = 1;i <= m;) {
		int tmp = i;
		//寻找同一家店同一时间的订单数量
		while(a[tmp].id==a[i].id&&a[tmp].tim==a[i].tim&&tmp<=m) tmp++;
		int tim = a[i].tim, id = a[i].id;//获取订单的时间和店的编号
		int cnt = tmp-i;//获取同一时刻订单的数量
		i = tmp;//tmp不为当前订单，所以是下一个需要处理的订单
		level[id] -= tim-last[id]-1;//修改定档优先级
		//由于只有中间部分没有订单（两边都有订单），所以需多-1
		if(level[id]<0) level[id] = 0;//最低的优先级为0
		if(level[id]<=3) pri[id] = 0;//小于3，不为优先缓冲
		level[id] += cnt*2;//订单期间添加的优先级
		if(level[id]>5) pri[id] = 1;//大于5，则加入到优先缓冲中
		last[id] = tim;//更新店id的上一个订单时间
	}
	for(int i = 1;i <= n;i++) {//遍历所有的店，计算有多少的店在优先缓冲区中
		if(last[i]<t) {//不在t时刻
			level[i] -= t-last[i];// last[i]-t 范围内优先级都需要减小
			if(level[i]<=3) pri[i] = 0;//小于3，则不在优先缓冲区中
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++) ans += pri[i];//统计结果
	cout<<ans<<endl;
	return 0;
}
