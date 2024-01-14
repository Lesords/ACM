#include<iostream>//ac
using namespace std;
int main() {
	int a,b;
	while(cin>>a>>b&&a&&b) {
		int flag = 0;
		for(int i = a*100;i<(a+1)*100;) {
			if(!(i%b)) {//可以整除
				if(flag) cout<<' ';//第一个不输出
				flag = 1;
				if((i%100)<10) cout<<"0"<<i%100;//个位数处理
				else cout<<i%100;
				i += b;//倍数加
			}
			else i++;
		}
		cout<<endl;
	}
	return 0;
}
