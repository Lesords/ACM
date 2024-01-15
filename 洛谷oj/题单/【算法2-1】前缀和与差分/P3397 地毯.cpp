#include<iostream>//ac
using namespace std;
const int MAXN = 1005;
int map[MAXN][MAXN];
int main() {
	int n,m,x1,y1,x2,y2;
	//地毯每覆盖一次就相当于区间内加1
	//多次区间加，即可使用差分+前缀和
	cin>>n>>m;
	while(m--) {
		cin>>x1>>y1>>x2>>y2;
		//二维差分
		//从x1到x2进行多次差分
		for(int i = x1;i <= x2;i++) {
			map[i][y1]++;//起点
			map[i][y2+1]--;//末点往后
		}
	}
	for(int i = 1;i <= n;i++) {
		int tmp = 0;//初始化为0，保存前缀和
		for(int j = 1;j <= n;j++) {
			if(j!=1) cout<<' ';
			tmp += map[i][j];
			cout<<tmp;//输出值
		}
		cout<<"\n";
	}
	return 0;
}
