#include<iostream>//ac 纯暴力
using namespace std;
int main() {
	int n,x,cnt = 0;
	cin>>n>>x;
	for(int i = 1;i <= n;i++) {//遍历所有数字
		int tmp = i;
		while(tmp) {//逐位判断
			if(tmp%10==x) cnt++;
			tmp /= 10;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
