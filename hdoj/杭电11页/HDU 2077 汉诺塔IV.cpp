#include<iostream>//ac
using namespace std;
int mid[22] = {0,1},a[22] = {0,2};
int main() {
	int t,tmp;
	//n个盘移到中心的大小：
	//将n-1个盘移动到第三个杆，为 2 * mid[n-1]
	//再将第n个pan移动到第二个杆去，为 1
	//最后将n-1个盘移动到第二杆去，为 mid[n-1]
	//=> mid[i] = 3 * mid[i-1] + 1; 
	for(int i = 2;i < 21;i++) 
		mid[i] = 3 * mid[i-1] + 1;
	//设第一个杆有n个盘
	//将n-1个盘移动到第二个杆中，为 mid[n-1] 
	//然后第n个盘无视大小,直接移到第三个杆去，为 2
	//最后将n-1个盘移动到第三个杆去，为 mid[n-1]
	//=> a[i] = 2 * mid[i-1] + 2; 
	for(int i = 2;i < 21;i++)
		a[i] = 2 * mid[i-1] + 2;
	cin>>t;
	while(t--) {
		cin>>tmp;
		cout<<a[tmp]<<endl;
	}
	return 0;
}
