#include<iostream>//ac
using namespace std;
int main() {
	int n,k,tmp,cnt = 0;
	cin>>n>>k;
	while(n--) {
		cin>>tmp;
		if(5-tmp>=k) cnt++;//达到标准的队员
	}
	cout<<cnt/3<<endl;//一个队三个人
	return 0;
}
