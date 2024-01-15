#include<iostream>//ac
#include<algorithm>
#define ll long long
#define two(x) (x)*(x)
using namespace std;
const int MAXN = 305;
int a[MAXN];
int main() {
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);//从小到大排序
	ll ans = 0;
	//第一先跳最大的，然后左右反复横跳即可
	int l = 1,r = n,hei = 0;
	while(l<=r) {
		ans += two(hei-a[r]);
		hei = a[r--];//更新hei大小
		//当l==r时，hei-a[l] = 0，所以无需考虑
		ans += two(hei-a[l]);
		hei = a[l++];//更新hei大小
	}
	cout<<ans;
	return 0;
}
