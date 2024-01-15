#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;

//题解：钝角三角形的特点是 最长边的平方 大于 其余两边的平方和
//三角形的条件是 最长边 小于 其余两边和
//也可判断 任意两边 的斜率来判断是否为三角形！！！

//也可根据 数量积 的正负值判断两个边的角度，判断三次
//（也需要判断三角形条件）
//数量积为0说明垂直，大于0则为锐角，小于0则为钝角

struct node{
	int x,y;
}a[505];
int two(int n) {return n*n;}
bool check(int i,int j,int k) {
	int len[4];
	len[1] = two(a[i].x-a[j].x)+two(a[i].y-a[j].y);//边的平方
	len[2] = two(a[i].x-a[k].x)+two(a[i].y-a[k].y);
	len[3] = two(a[j].x-a[k].x)+two(a[j].y-a[k].y);
	sort(len+1,len+4);//从小到大排序
	//最长边的平方和 大于 其余两边的平方和 && 最长边 < 其余两边和
	if(len[3]>len[2]+len[1]&&sqrt(len[3])<sqrt(len[2])+sqrt(len[1]))
		return true;
	return false;
}
int main() {
	int n,ans = 0;
	cin>>n;
	for(int i = 1;i <= n;i++) cin>>a[i].x>>a[i].y;
	for(int i = 1;i <= n;i++) {//保证不重复
		for(int j = i + 1;j <= n;j++) {//i的后一位
			for(int k = j + 1;k <= n;k++) {//j的后一位
				if(check(i,j,k)) ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
