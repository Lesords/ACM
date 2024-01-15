#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：快速排序，每次的基准数取中间值
//都选择左边为基准数，会被有序（接近有序）的数组卡到O(n^2)
//选择中间为基准数，在操作的过程中，基准数的位置也可能被移动

const int MAXN = 1e5 + 5;
int a[MAXN];
void quicksort(int l,int r) {           //[l,r]区间内排序
	int left = l,right = r;
	int mid = a[(l+r)/2];               //取中间值为基准数
	//相等的时候还需要继续，因为接下来的递归r在左，l在右
	while(l<=r) {
        //l和r的位置不受限制
        //因为边界位置是 (l+r)/2，这个位置l和r都满足条件
        while(a[l]<mid) l++;            //寻找左部分大于等于mid的位置
        while(a[r]>mid) r--;            //寻找有部分小于等于mid的位置
        //l可以等于r！！！（都处于边界位置时）
		if(l<=r) swap(a[l],a[r]),l++,r--;//交换值，并移动l和r的位置！！！
	}
    if(left<r) quicksort(left,r);       //存在左区间
	if(l<right) quicksort(l, right);    //存在右区间
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i];
	quicksort(1,n);
	for(int i = 1;i <= n;i++) {
		if(i!=1) cout<<' ';
		cout<<a[i];
	}
	return 0;
}
