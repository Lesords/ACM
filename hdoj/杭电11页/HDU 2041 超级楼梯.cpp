#include<iostream>//ac
using namespace std;
int a[45];
int main() {
	int n,tmp;
	cin>>n;
	a[1] = 0, a[2] = 1, a[3] = 2;//Ҫô��ǰһ����Ҫô��ǰ����
	for(int i=4;i<=42;i++) a[i] = a[i-1] + a[i-2];
	while(n--) {
		cin>>tmp;
		cout<<a[tmp]<<endl;
	}
	return 0;
} 
