#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 3e4 + 5;
int a[MAXN];
int main() {
	int w,n;
	cin>>w>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+1+n);//从小到大排序
	int l = 1,r = n,ans = 0;
	while(l<=r) {//l为左指针，r为右指针
		ans++;//每次都增加一个分组
		if(l==r) break;//每次先判断大后判断小
		int tmp = a[r--];//先大,并且移动右指针
		if(tmp+a[l]<=w) l++;//判断剩余空间是否够放左纪念品
	}
	cout<<ans;
	return 0;
}
