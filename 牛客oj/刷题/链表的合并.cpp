#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[35];
int main() {
	for(int i = 1;i <= 30;i++) cin>>a[i];
	sort(a + 1, a + 31);
	for(int i = 1;i <= 30;i++) {
		if(i!=1) cout<<' ';
		cout<<a[i];
	}
	cout<<endl;
	return 0;
}
