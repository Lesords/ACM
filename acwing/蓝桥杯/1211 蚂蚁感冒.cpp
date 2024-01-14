#include<iostream>//wa
#include<algorithm>
using namespace std;
int a[55];
int main() {
	int n,dir,ans = 1;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	dir = a[1]<0?-1:1;
	for(int i = 2;i <= n;i++) {
		cout<<ans<<" ";
		if(dir==1&&abs(a[i])>abs(a[1])&&a[i]<0) ans++;
		if(dir==-1&&abs(a[i])<abs(a[1])&&a[i]>0) ans++;
		cout<<i<<" "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
