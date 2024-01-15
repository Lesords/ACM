#include<iostream>//ac
#include<cmath>
using namespace std;
int main() {
	int t,n,x;
	cin>>t;
	while(t--) {
		int ans = 0,tmp,maxx = 0;
		cin>>n>>x;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			maxx = max(maxx,tmp);//记录最大值
			if(tmp==x) ans = 1;//刚好有一步到达终点的
		}
		if(ans) {//一步到
			cout<<ans<<endl;
			continue;
		}//除了一步到，其他最少需要两步（不管大还是小）
		//另外的一种情况就是判断需要几个maxx步（向上取整）
		//应该可以走的距离为 maxx - 2*maxx 中任意值 ！！！
		//差多少距离都要多算一步
		ans = max(2.0,ceil(x*1.0/maxx*1.0));
		cout<<ans<<endl;
	}
	return 0;
}
