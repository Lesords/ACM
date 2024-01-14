#include<iostream>
#include<cstring> 
#include<queue>
using namespace std;
struct node {
	char num[25];
	int rp;//人品 
	friend bool operator < (struct node a,struct node b) {
		if(a.rp!=b.rp) return a.rp>b.rp;//最差先踢 
		else return strcmp(a.num,b.num)<0;
	}
};
int main() {
	int n,m;
	while(cin>>n>>m) {
		priority_queue<node> q[10005];
		for(int i=1;i<=n;i++) {
			int k;
			cin>>k;
			for(int j=1;j<=k;j++) {
				node temp;
				cin>>temp.num>>temp.rp;
				q[i].push(temp);
			}
		}
		for(int i=1;i<=m;i++) {
			string str;
			int rnum;//当前车厢号 
			cin>>str>>rnum;
			if(str=="GETOUT") {
				node ans;
				ans=q[rnum].top();
				cout<<ans.num<<endl;
				q[rnum].pop();
			}
			if(str=="JOIN") {
				int num2;
				node ans2;
				cin>>num2;
				while(!q[num2].empty()) {
					ans2=q[num2].top();
					q[rnum].push(ans2);
					q[num2].pop();
				}
			}
			if(str=="GETON") {
				node ans3;
				cin>>ans3.num>>ans3.rp;
				q[rnum].push(ans3);
			}
		}
	}
	return 0;
}
