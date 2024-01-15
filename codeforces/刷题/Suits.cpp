#include<iostream>//ac
#include<algorithm>
using namespace std;
int main() {
	int a,b,c,d,e,f,ans = 0,minn;
	cin>>a>>b>>c>>d>>e>>f;
	if(f>e) {//先组贵的一套，再判断剩余d是否可以组成另外一套
		minn = min(b,min(c,d));
		ans += minn * f;
		d -= minn;
		ans += min(a,d) * e;
	}
	else {
		minn = min(a,d);
		ans += minn * e;
		d -= minn;
		ans += min(b,min(c,d)) * f; 
	}
	cout<<ans<<endl; 
	return 0;
}
