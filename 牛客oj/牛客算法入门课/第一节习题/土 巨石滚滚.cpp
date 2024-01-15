#include<iostream>//ac
#include<queue>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
struct node{
	ll a,b,c;
	friend bool operator < (node x,node y) {
		//正反馈的时候需要先撞稳定性小的
		if(x.a!=y.a) return x.a > y.a;
		return x.b < y.b;
	}
};
struct node1{
	ll a,b,c;
	friend bool operator < (node1 x,node1 y) {
		//负反馈的时候需要先撞回馈多的！！！
		if(x.b!=y.b) return x.b < y.b;
		return x.a > y.a;
	}
/*
1
2 30
1 0
30 5
wa样例
*/
};
int main() {
	ll t,n,m;
	cin>>t;
	while(t--) {
		priority_queue<node> add;
		priority_queue<node1> minus;
		cin>>n>>m;
		ll a,b,op;
		for(int i = 1;i <= n;i++) {
			cin>>a>>b;
			op = b-a;//判断是正还是负反馈
			if(op>=0) add.push(node{a,b,op});
			else minus.push(node1{a,b,op});
		}
		int flag = 1;
		node tmp;
		while(!add.empty()) {//先正反馈
			tmp = add.top(),add.pop();
			if(m<tmp.a) {//判断是否会散架
				flag = 0;
				break;
			}
			else m += tmp.c;
		}
		node1 tmp1;
		//前面散架了后面就不需要判断了
		while(flag&&!minus.empty()) {//然后负反馈
			tmp1 = minus.top(),minus.pop();
			if(m<tmp1.a) {
				flag = 0;break;
			}
			else m += tmp1.c;
		}
		cout<<(flag?"Yes\n":"No\n");
	}
	return 0;
}
