#include<iostream>//ac
using namespace std;

//题意：求解(x,y) 最上方的地毯编号（不是数量）！！！
//题解：遍历所有地毯直接判断(x,y)是否在地毯范围内即可（可逆序查找）

const int MAXN = 1e6 + 5;
struct node{
	int x,y,xl,yl;
}map[MAXN];
int main() {
	int n,a,b,g,k,x,y;
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>map[i].x>>map[i].y>>map[i].xl>>map[i].yl;
	}
	int ans = 0;
	cin>>x>>y;
	for(int i = 1;i <= n;i++) {//可逆序查找（找到直接退出）
		//先计算地毯的左右范围
		int l_x = map[i].x, r_x = map[i].x + map[i].xl;
		int l_y = map[i].y, r_y = map[i].y + map[i].yl;
		if(l_x<=x&&x<=r_x&&l_y<=y&&y<=r_y) ans = i;//实时更新
	}
	cout<<(ans?ans:-1)<<endl;//技巧输出
	return 0;
}
