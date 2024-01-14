#include<iostream>//ac
#include<cmath>
using namespace std;
int a[55];
int main() {
	int n,flag = 0;
	while(cin>>n&&n) {
		int sum = 0,cnt = 0;
		if(flag++) cout<<endl;//pe点
		for(int i = 1;i<=n;i++) {
			cin>>a[i];
			sum += a[i];
		}
		sum /= n;//墙的高度
		for(int i = 1;i<=n;i++)
			cnt += abs(sum-a[i]);//每个墙与平均高度的差距
		cout<<cnt/2<<endl;//移动的时候一边多一边少
	}
	return 0;
} 
