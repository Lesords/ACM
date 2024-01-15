#include<iostream>//ac
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN],dif[MAXN];
int main() {
	int L,M,l,r,ans = 0;
	cin>>L>>M;
	//初始化  1为有树
	for(int i = 0;i <= L;i++) a[i] = 1;
	for(int i = 1;i <= M;i++) {
		cin>>l>>r;
		//l-r  区间内的树数量--
		dif[l]--,dif[r+1]++;
	}
	a[0] += dif[0];//起点更新！！！
	for(int i = 1;i <= L;i++) {
		a[i] = a[i-1]+dif[i];//更新当前位置的树数量
		if(a[i]>=1) ans++;//有树则ans++
	}
	cout<<ans+a[0];//需加上0位置的树数量
	return 0;
}
