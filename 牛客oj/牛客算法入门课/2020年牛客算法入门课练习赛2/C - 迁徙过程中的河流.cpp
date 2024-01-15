#include<iostream>//wa
#include<cstdio>
#include<cstring>
#include<cmath>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<algorithm>
#define ll long long
#define fi first
#define se second
using namespace std;
const int MAXN = 1e5+5;
int main() {
	int n,ans = 0,tmp;
	priority_queue<int,vector<int>,greater<int> > p;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>tmp;
		p.push(tmp);
	}
	int a,b;
	if(p.size()==1) {
		cout<<p.top()<<endl;
		return 0;
	}
	while(!p.empty()) {
		a = p.top(),p.pop();
		if(p.empty()) {
			ans += a;break;
		}
		b = p.top(),p.pop();
		ans += max(a,b);
		if(!p.empty()) p.push(min(a,b)),ans += min(a,b);
	}
	cout<<ans;
	return 0;
}
