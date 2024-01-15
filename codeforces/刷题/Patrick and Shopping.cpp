#include<iostream>//ac
#include<algorithm>
//更新三个点之间的两两距离，再计算总和 
using namespace std;
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	a = min(a,c+b);
	b = min(b,c+a);
	c = min(c,a+b);
	cout<<a+b+c<<endl;
	return 0;
} 
