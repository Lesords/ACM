#include<iostream>//ac
using namespace std;
int get(int n) {
	int cnt = 0;
	while(n) cnt++,n /= 10;
	return cnt;
} 
int main() {
	int n,t,minn,maxx;
	cin>>n>>t;
	if(get(t)>n) {
		cout<<"-1"<<endl;
		return 0;
	}
	cout<<t;
	for(int i = get(t)+1;i<=n;i++) cout<<'0';
	cout<<endl;
	return 0;
} 
