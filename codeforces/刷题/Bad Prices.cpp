#include<iostream>
using namespace std;
int main() {
	int T,a[150005]; cin>>T;
	while(T--) {
		int n,ans=0;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=n;i>=2;i--) {//从后开始判断 
			if(a[i]<a[i-1]) {//后面一个数比前面小（bad）
				ans++;
				a[i-1]=a[i];//小的数往前移
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
