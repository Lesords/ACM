#include<iostream>//ac
#include<string>
using namespace std;
int main() {
	string a;
	while(cin>>a) {
		if(a.size()%2) {//奇数
			cout<<"NO"<<endl;
		}
		else {
			int mid = a.size()/2;
			int flag = 0;//0 和 mid 分别为起点
			for(int i = 0,j = mid;j < a.size();i++,j++) {
				if(a[i]!=a[j]) {//不相等
					flag = 1;break;
				}
			}
			if(flag) cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
	return 0;
}
