#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
int a[MAXN], b[MAXN];
bool cmp(int a,int b) {
	return a > b;
}
int main() {
	int t;
	long long ans = 0;
	cin>>t;
	for(int i = 1;i <= t;i++) cin>>a[i];
	sort(a + 1, a + t + 1);
	for(int i = 1;i <= t;i++) cin>>b[i];
	sort(b + 1, b + t + 1,cmp);
	for(int i = 1;i <= t;i++) {
		if(b[i]>a[i]) ans += b[i] - a[i];
	}
	cout<<ans<<endl;
	return 0;
}
