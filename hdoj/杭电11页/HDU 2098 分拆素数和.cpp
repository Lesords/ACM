#include<iostream>//ac
using namespace std;
int a[10005];
int main() {
	for(int i=2;i<=10000;i++) {
		if(a[i]) continue;
		for(int j=i+i;j<=10000;j+=i)//i + i开始
			a[j] = 1;
	}
	int n;
	while(cin>>n&&n) {
		int ans = 0;
		for(int i=2;i<=n/2;i++) {
			if(!a[i]&&!a[n-i]&&i!=n-i) ans++;
			//两个都是素数且不相等
		}
		cout<<ans<<endl; 
	}
	return 0;
}
