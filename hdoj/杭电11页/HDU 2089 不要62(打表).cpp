#include<iostream>//ac
using namespace std;
const int MAXN = 1e6 + 5;
int a[MAXN];
bool f(int i) {
	while(i) {
		if(i%10==4||i%100==62) return false;
		i /= 10;
	}
	return true;
}
int main() {
	int n,m;
	a[0] = 1;
	for(int i = 1;i < MAXN;i++) {
		if(f(i)) a[i] = a[i-1] + 1;
		else a[i] = a[i-1];
	}
	while(cin>>n>>m&&n+m) {//包括该两个数
		cout<<a[m] - a[n-1]<<endl;
	}
	return 0;
}
