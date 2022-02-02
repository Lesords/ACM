#include<iostream>//ac
using namespace std;
int main() {
	int x,n,ans = 0;
	cin>>x>>n;
	while(n--) {//时间跨度
		if(x<=5) ans += 250;//非周末
		//x = x%7 + 1; 比较巧妙
		x++;
		if(x>7) x = 1;
	}
	cout<<ans<<endl;
	return 0;
} 
