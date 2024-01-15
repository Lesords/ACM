#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[105];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int num = unique(a+1,a+n+1) - a;
	//unique返回末端第一个重复的数地址
	cout<<num-1<<endl;
	for(int i = 1;i < num;i++) {//不包括num
		if(i!=1) cout<<' ';
		cout<<a[i];
	}
	return 0;
}
