#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	int t,n,x,a,b;
	cin>>t;
	while(t--) {
		cin>>n>>x>>a>>b;
		//最大距离为n-1,初始距离为abs(a-b)，增加的距离为x
		cout<<min(n-1,abs(a-b)+x)<<endl;
	}
	return 0;
}
