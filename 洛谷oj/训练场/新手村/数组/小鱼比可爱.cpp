#include<iostream>//ac
using namespace std;
int a[105],ans[105];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	for(int i = 2;i <= n;i++) {//1为0，则从2开始遍历
		for(int j = 1;j < i;j++) {
			if(a[j] < a[i]) ans[i]++;
		}
	}
	for(int i = 1;i <= n;i++) {
		if(i!=1) cout<<' ';
		cout<<ans[i];
	}
	cout<<endl;
	return 0;
}
