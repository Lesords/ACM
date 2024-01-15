#include<iostream>//ac
using namespace std;
int a[15];
int main() {
	int height, ans = 0;
	for(int i = 1;i <= 10;i++) cin>>a[i];
	cin>>height;
	for(int i = 1;i <= 10;i++) {
		if(a[i]<=height+30) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
