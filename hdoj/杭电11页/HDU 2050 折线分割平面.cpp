#include<iostream>//ac
#define ll long long
using namespace std;
const int MAXN = 1e4 + 5;
ll a[MAXN]={1};
int main() {
	int t,tmp;
	for(int i = 1;i < MAXN;i++)
		a[i] = a[i-1] + 4*(i-1)+1;
	//折线y一定有一个固定的1，加上左右共两边需乘2
	//单边穿过的线条数量又为2(n-1)个
	//所以每次多出来的区域大小为：4*(n-1)+1
	cin>>t;
	while(t--) {
		cin>>tmp;
		cout<<a[tmp]<<endl;
	}
	return 0;
}
