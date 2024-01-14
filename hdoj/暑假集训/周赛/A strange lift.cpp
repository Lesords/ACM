#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int flr[201],book[201];
struct node {
	int data,step;
	friend bool operator < (node a,node b) {
		return a.step>b.step;
	}
};
int main() {
	int n;
	while(cin>>n) {
		if(n==0) break;
		int a,b;
		cin>>a>>b;
		memset(flr,0,sizeof(flr));
		memset(book,0,sizeof(book));
		for(int i=1;i<=n;i++) {
			cin>>flr[i];
		}
		int flag=0,ans=0;
		priority_queue<node> q;
		node now;
		now.data=a;
		now.step=0;
		q.push(now);
		while(!q.empty()) {
			now=q.top();
			q.pop();
			if(now.data==b) {
				flag=1;
				ans=now.step;
				break;
			}
			if(now.data+flr[now.data]<=n&&
			!book[now.data+flr[now.data]]) {//上楼梯和下楼梯要分开计算 
				node tmp;
				tmp.data=now.data+flr[now.data];
				tmp.step=now.step+1;
				q.push(tmp);
				book[tmp.data]=1;
			}
			if(now.data-flr[now.data]>=1&&
			!book[now.data-flr[now.data]]) {
				node tmp;
				tmp.data=now.data-flr[now.data];
				tmp.step=now.step+1;//都是加 
				q.push(tmp);
				book[tmp.data]=1;
			}
		}
		if(flag) cout<<ans<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
} 
