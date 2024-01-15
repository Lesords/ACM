#include<iostream>//ac
using namespace std;
int main() {
	int n,ans = 0;
	cin>>n;
	while(n) {
		if(n&1) ans++;
		//二进制向左移动都是2倍
		//则只需要判断出现多少个有效的1
		n >>= 1;
	}
	cout<<ans<<endl;
	return 0;
} 
