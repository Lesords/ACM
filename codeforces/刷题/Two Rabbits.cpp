#include<iostream>//ac
using namespace std;
int main() {
	int t,x,y,a,b;
	cin>>t;
	while(t--) {
		cin>>x>>y>>a>>b;
		//判断x与y之间的距离是否为（a+b）的倍数即可
		if((y-x)%(a+b)==0) cout<<(y-x)/(a+b)<<endl;
		else cout<<"-1"<<endl;
	}
	return 0;
}
