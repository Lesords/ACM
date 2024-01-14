#include<iostream>//ac
using namespace std;
long long a[36] = {0,2};//简单定义方式
int main() {
	int n;
	//设第一个杆上有n个盘，将n-1个盘移到第三个杆需要 a[n-1]
	//将第 n 个盘移到第二个杆需要 +1
	//然后将 n-1 个盘移到第一个杆也需要 a[n-1]
	//将第 n 个盘移到第三个杆还需要 +1
	//最后将 n-1 个盘移到第三个杆也需要 a[n-1]
	//=> a[n] = 3*a[n-1] + 2
	for(int i = 2;i < 36;i++) {
		a[i] = 3 * a[i-1] + 2;
	}
	while(cin>>n) {
		cout<<a[n]<<endl;
	}
	return 0;
} 
