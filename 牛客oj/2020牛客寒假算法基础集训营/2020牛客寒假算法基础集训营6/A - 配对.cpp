#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;

//题解：取最大化第k大的和，那么可以将两个数组都升序排列
//然后将两个数组中的前k个进行配对
//（后面的排名不受影响，对应相加）！！！
//发现最大化第k大的话，就是将a数组前k个升序，b数组前k个降序
//然后对应相加，最小值即为第k大

const int MAXN = 1e5 + 5;
int a[MAXN],b[MAXN];
bool cmp(int a,int b) {//升序
	return a>b;
}
int main() {
	int n,k,ans;
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	for(int i = 1;i <= n;i++) scanf("%d",&b[i]);
	sort(a+1,a+n+1,cmp);//升序排列
	sort(b+1,b+n+1,cmp);
	ans = a[1]+b[1];//初始化为两个最大值的和
	//O(N)操作，无需多余数组
	for(int i = 1;i <= k;i++) {//a为升序，b为降序
		ans = min(ans,a[i]+b[k-i+1]);//对应取较小值
	}//最后的ans即为第k大值
	printf("%d",ans);
	return 0;
}
