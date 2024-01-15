#include<iostream>//ac
using namespace std;

//题解：比较相邻的深度，右边的比左边深的时候需要再填充右边区域

int main() {
	int t,a,tmp = 0,ans = 0;//初始化为平地0
	cin>>t;
	while(t--) {
		cin>>a;
		if(a>tmp) ans += a - tmp;//深度差
		tmp = a;
	}
	cout<<ans<<endl;
	return 0;
}
