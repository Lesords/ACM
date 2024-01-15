#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 2e5 + 5;
int a[MAXN],l_r[MAXN],r_l[MAXN];
//题解：先从左到右扫一遍，记录 左 递增序列块的长度，并更新ans
//再从右到左扫一遍，记录 右 递增序列块的长度，并更新ans
//最后判断 隔一个数 的左右两个部分是否为递增序列，并更新ans
int main() {
	int t,ans = 1;//初始值为1，因为至少会有一个数
	cin>>t;
	for(int i = 1;i <= t;i++) cin>>a[i];
	l_r[1] = r_l[t] = 1;//初始化
	for(int i = 2;i <= t;i++) {//去除初始位 (i为终点)
		if(a[i]>a[i-1])//比左边的数大
			l_r[i] = l_r[i-1] + 1,ans = max(ans,l_r[i]);
		else l_r[i] = 1;
	}
	for(int i = t-1;i >= 1;i--) {//去除初始位 (i为起点)
		if(a[i]<a[i+1])//比右边的数小
			r_l[i] = r_l[i+1] + 1,ans = max(ans,r_l[i]);
		else r_l[i] = 1;
	}
	for(int i = 1;i + 2 <= t;i++) {
		if(a[i] < a[i+2]) ans = max(ans,l_r[i]+r_l[i+2]);
	}
	cout<<ans<<endl;
	return 0;
}
