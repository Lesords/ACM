#include<iostream>//ac
using namespace std;
long long a[55],n;//ll��
int main() {
	a[1] = 1,a[2] = 2;
	for(int i=3;i<=52;i++) a[i] = a[i-1] + a[i-2];
	//nΪ4��ʱ�򣬿��԰�һ������(i-1)����������(i-2)��
	while(cin>>n) {
		cout<<a[n]<<endl;
	}
	return 0;
} 
