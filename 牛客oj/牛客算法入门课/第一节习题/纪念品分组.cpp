#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 3e4+5;
int a[MAXN];
int main() {
	int w,k;
	cin>>w>>k;
	for(int i = 1;i <= k;i++) cin>>a[i];
	sort(a+1,a+k+1);//升序
	int l = 1, r = k,ans = 0;
	while(l<=r) {
		if(l==r) l++,ans++;//位于同一个位置
		else if(a[r]+a[l]>w) r--,ans++;//只能分配较大值为一组
		else r--,l++,ans++;//两个一组
	}
	cout<<ans;
	return 0;
}
