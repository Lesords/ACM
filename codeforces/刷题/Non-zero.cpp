#include<iostream>//ac
using namespace std;
int main() {
	int t,n;
	cin>>t;
	while(t--) {
		cin>>n;
		int tmp,cnt,sum;
		cnt = sum = 0;
		for(int i = 1;i <= n;i++) {
			cin>>tmp;
			sum += tmp;
			if(tmp==0) cnt++;//0是必操作的数量
		}//结果还为0时需要在操作一次
		cout<<cnt+(sum+cnt==0?1:0)<<endl;
	}
	return 0;
}
