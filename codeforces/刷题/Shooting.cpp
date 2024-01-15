#include<iostream>//ac
#include<algorithm>
using namespace std;
struct node {
	int a,b;
	friend bool operator < (node x, node y) {
		return x.a<y.a;
	}
}a[1005];
int main() {
	int T,ans=0;
	cin>>T;
	for(int i=1;i<=T;i++) {
		cin>>a[i].a;
		a[i].b=i;
	}
	sort(a+1,a+T+1);
	for(int i=T,j = 0;i>=1;i--,j++) {
		ans += a[i].a * j + 1;
	}
	cout<<ans<<endl;
	for(int i=T;i>=1;i--) {//ÄªÃûac
		cout<<a[i].b<<' ';
	}
	return 0;
}
