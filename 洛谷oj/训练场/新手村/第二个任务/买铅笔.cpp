#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
int main() {
	int n,a,b,minn = INF;
	cin>>n;
	for(int i = 1;i <= 3;i++) {
		cin>>a>>b;//a为数量，b为价格
		if((n/a)*a >= n) minn = min(minn, b*(n/a));
		else minn = min(minn, b*(n/a+1));//需要多买一包
	}
	cout<<minn<<endl;
	return 0;
}
