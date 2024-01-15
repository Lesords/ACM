#include<iostream>
#include<queue>
using namespace std;
int main() {
	int n;
	cin>>n;
	priority_queue<int,vector<int>, greater<int> > q;
	while(n--) {
		int m;
		cin>>m;
		q.push(m);
	}
	int ans=0,tmp,cnt=1;
	while(!q.empty()) {
		tmp=q.top();
		q.pop();
		if(tmp>=cnt) {
			ans++;
			cnt++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
