#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
	int t,a[4];
	cin>>t;
	while(t--) {
		cin>>a[1]>>a[2]>>a[3];
		sort(a+1,a+4);
		//最大值大于两个小的之和时，可将两个小的认为是同一种糖果
		//否则的话，这三种糖果绝对会分成两两结合的，也就是总和/2
		if(a[3]>=a[1]+a[2]) cout<<a[1]+a[2]<<endl;
		else cout<<(a[1]+a[2]+a[3])/2<<endl;
		//可用a[3]-a[2]的值与a[1]结合使用
		//然后此时a[2]=a[3]，a[1] = a[1] - (a[3]-a[2])
		//此时为两个相同一个不同，则一定可以分完
	}
	return 0;
}
