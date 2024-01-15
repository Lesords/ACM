#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
struct node{
	//左下角坐标即x，y轴长度
	int x,y,xp,yp;
}a[MAXN];
int main() {
	int n,x,y,ans = -1;//ans初始化为-1
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i].x>>a[i].y>>a[i].xp>>a[i].yp;
	}
	cin>>x>>y;
	for(int i = n;i >= 1;i--) {
		//逆序判断是否在当前地毯范围内
		if(a[i].x<=x&&x<=a[i].x+a[i].xp&&
		a[i].y<=y&&y<=a[i].y+a[i].yp) {
			ans = i;break;
		}
	}
	cout<<ans;
	return 0;
}
