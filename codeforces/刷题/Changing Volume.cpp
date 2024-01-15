#include<iostream>//ac
#include<cmath>
using namespace std;
int main() {
	int t,a,b;
	cin>>t;
	while(t--) {
		cin>>a>>b;
		int tmp = abs(a-b);//取绝对值，然后按从大到小递减
		int cnt = tmp/5;
		tmp %= 5;
		cnt += tmp/2;
		tmp %= 2;
		cnt += tmp;
		//也可把最后一下当做为2，即结果为（cnt/5 + (cnt%5+1)/2）
		cout<<cnt<<endl;
	}
	return 0;
}
