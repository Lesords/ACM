#include<iostream>//ac
#include<algorithm>
using namespace std;
int f(int n) {
	int cnt = 1;
	while(n!=1) {
		if(n%2) n = 3*n+1;
		else n = n/2;
		cnt++;
	}
	return cnt;
}
int main() {
	int a,b;
	while(cin>>a>>b) {//不保证 a一定小于b！！！
		int maxx = 0;
		int l = min(a,b);
		int r = max(a,b);
		for(int i = l;i <= r;i++) {
			maxx = max(maxx,f(i));
		}
		cout<<a<<' '<<b<<' '<<maxx<<endl;
	}
	return 0;
}
