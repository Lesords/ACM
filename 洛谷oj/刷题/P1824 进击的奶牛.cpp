#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN],n,c;
bool check(int mid) {
//第一个奶牛肯定放在第一个隔间，所以只需要判断剩余的即可
	int pos = 1,next = 2,num = 2;
	//pos为当前位置，next为下一个奶牛的位置
	while(num<=c) {//共c个奶牛
		//不越界并且距离要满足>=mid
		while(next<=n&&a[next]-a[pos]<mid) next++;
		if(next>n) return 0;//如果next超了，说明不可行
		pos = next++;//更新当前位置和下一位置
		num++;//已分配的奶牛数量++
	}
	return 1;
}
int main() {
	cin>>n>>c;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a+1,a+n+1);//从小到大排序
	//二分的最大值为首尾的距离
	int l = 1,r = a[n]- a[1],ans = 0;//ans初始化为0
	while(l<=r) {//二分查找答案
		int mid = (l+r)/2;
		if(check(mid)) ans = mid,l = mid+1;
		else r = mid-1;
	}
	cout<<ans;
	return 0;
}
