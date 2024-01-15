#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[20],ans = 1;//初始化为1（肯定会有一个）
void binal_search(int l,int r) {//二分查找
	if(l>=r) return;//结束条件
	int mid = (l+r)/2;
	int tmp = 1;
	for(int i = l;i < r;i++) {//遍历是否符合升序
		if(a[i]<=a[i+1]) tmp++;
		else {tmp = 1;break;}//有一个不符合都不行
	}
	ans = max(ans,tmp);//更新最大区间
	if(tmp!=1) return;//找到结果后直接返回（继续递归值会小）
	binal_search(l,mid);//左递归
	binal_search(mid+1,r);//右递归
}
int main() {
	int n;cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	binal_search(1,n);//二分查找判断
	cout<<ans<<endl;
	return 0;
}
