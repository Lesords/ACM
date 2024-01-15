#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 5e4+10;
int len,n,m,a[MAXN];//len是最长距离
bool check(int mid) {//判断mid是否可行
	//pos为当前位置，next为跳的目的位置
	int pos = 0,next = 1,num = 0;//num为移动的石头数量
	//最后要到第n+1个石头的位置(最后一个石头)
	while(pos<n+1) {//如果还没有到达最后一个石头
		while(a[next]-a[pos]<mid) {//判断
			if(next>n+1) return 0;//next越界(即没有满足的情况)
			next++;//next往后移一步，就需要移走一个石头
			num++;
			if(num>m) return 0;//移动的石头数量过多
		}
		pos = next++;//当前位置更新为next,next需后移
	}
	return 1;
}
int main() {
	cin>>len>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	a[n+1] = len;//起始点为零，最后一个(n+1)为len
	int l = 1,r = len;
	while(l<=r) {//二分查找
		int mid = (l+r)/2;
		if(check(mid)) l = mid+1;//也可在此用ans维护
		else r = mid-1;
	}
	cout<<r<<endl;//r为最后的结果，因为l右移
	//r要么不变，要么左移(左移为可行数)
	return 0;
}
