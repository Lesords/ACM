#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n,m;
	cin>>n;
	priority_queue<int,vector<int>,greater<int> > q;
	for(int i=1;i<=n;i++) {
		cin>>m;
		q.push(m);
	}
	int ans=0,a,b;
	while(!q.empty()) {
		a=q.top();
		q.pop();
		b=q.top();
		q.pop();
		ans+=a+b;
		if(q.size()>=1)q.push(a+b);
	}
	cout<<ans<<endl;
	return 0;
} 
