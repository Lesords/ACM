#include<iostream>//ac
#include<algorithm>
//先从小到大排序
//然后最大值A = a[4] - a[1] ((a+b+c) - (a+b))
//由于第二大总数中一定包括A，则可求出第二大B = a[3] - A
//最后一个值C则为总和减去A和B，即为 C = a[4] - A - B 
using namespace std;
int a[5];
int main() {
	for(int i = 1;i <= 4;i++) cin>>a[i];
	sort(a+1,a+5);
	int A = a[4] - a[1];
	int B = a[3] - A;
	int C = a[4] - A - B;
	cout<<A<<' '<<B<<' '<<C<<endl; 
	return 0;
}
