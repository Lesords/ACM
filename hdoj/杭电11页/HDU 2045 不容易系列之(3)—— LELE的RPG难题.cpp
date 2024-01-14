#include<iostream>
#define ll long long
using namespace std;
ll a[55]={0,3,6,6};
int main() {
	for(int i = 4 ;i <= 50;i++) 
		a[i] = a[i-1] + a[i-2] * 2;
	//第n-1个颜色与第1个颜色不相同 (a[i-1])
	/*第n-2个颜色与第1个颜色不相同 (a[i-2])
	那么第n-1个颜色可以与第1个相同
	所以第n个就有两个颜色选择*/ 
	int n;
	while(cin>>n) cout<<a[n]<<endl;
	return 0;
}
