#include<iostream>//ac
using namespace std;
int main() {
	int a,b,ans = 0,cnt = 0;
	cin>>a>>b;
	while(a) {
		ans++;//结果
		cnt++;//标记旧的蜡烛数量
		if(cnt==b) a++,cnt = 0;//制造一个新的，标记清零
		a--;//蜡烛减少
	}
	cout<<ans<<endl;
	return 0;
} 
