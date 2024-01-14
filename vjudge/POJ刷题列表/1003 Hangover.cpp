#include<iostream>//ac
using namespace std;
int main() {
	double a;
	while(cin>>a) {
		if(a==0) break;//0结束输入
		double ans = 0,cnt = 1;
		while(ans<a) {//ans用来记录悬挂的长度
			cnt++;//牌数量++
			ans += 1.0/cnt;//从2开始计算（1根）
		}
		cout<<cnt-1<<" card(s)"<<endl;
	}
	return 0;
} 
