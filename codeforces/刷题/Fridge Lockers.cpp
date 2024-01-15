#include<iostream>//ac
#include<string>
//题意：一个冰箱可以有多个铁链绑着，只有所有的铁链都解锁了，才能开冰箱
//每个人都可以知道与自己相连的铁链密码,求花费最少的铁链费用

//题解：也就是说每个冰箱只要有两个铁链绑着就是为私人的冰箱
//（其他人都只能开一个铁链）
//那么所有的冰箱绑成环即为最小花费费用（铁链数恰好为冰箱数）
//总的费用为所有的冰箱重量 * 2（每个冰箱都连两次）
using namespace std;
int main() {
	int t,n,m;
	cin>>t;
	while(t--) {
		cin>>n>>m;
		int tmp,sum = 0;
		for(int i = 1;i <= n;i++) cin>>tmp,sum+=tmp;
		if(n!=m||n==2) cout<<"-1"<<endl;//m=n时，花费最小
		else {
			cout<<sum*2<<endl;//花费为两个点相加，则每个点都会加两次
			for(int i = 1;i <= n;i++) {//输出一个环的对应边
				cout<<i<<' '<<i%n + 1<<endl;
			}
		}
	}
	return 0;
}
