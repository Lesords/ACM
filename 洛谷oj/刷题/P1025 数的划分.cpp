#include<iostream>//ac
#include<algorithm>
using namespace std;
int a[10] = {1},ans,n,k;
void dfs(int step,int rest) {//step为已完成的数量，rest为剩余值
	if(step==k) {//分配k个
		if(rest==0) ans++;//全部分配完
		return;
	}
	//下一个分配的为 step+1
	//剩余 step+1 -> k ，共 k-step 个
	//判断剩余的是否可以构成 k-step 个大于等于前一个数的值
	if(rest/(k-step)<a[step]) return;
	//以 前一个数的值为起点
	//以 判断剩余的值是否可以构成 k-step 个数 为条件
	for(int i = a[step];i*(k-step) <= rest;i++) {
		a[step+1] = i;//记录 step+1 位置的值
		dfs(step+1,rest-i);//更新位置和剩余值继续递归
	}
}
int main() {
	cin>>n>>k;
	dfs(0,n);
	cout<<ans;
	return 0;
}
