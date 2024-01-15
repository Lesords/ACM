#include<iostream>
#include<algorithm>
using namespace std;
int a[5];
int main() {
	int tmp;
	for(int i=1;i<=4;i++) {
		cin>>a[i];
	}
	sort(a+1,a+5);
	int cnt=unique(a+1,a+5)-&a[1];//unique返回值为非重复数的下一点
	cout<<4-cnt<<endl;
	return 0;
}
