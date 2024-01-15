#include<iostream>//ac
#include<cstdio>
using namespace std;

//题解：需要注意的是数组越位行为不只是负数还有超范围
//还有产生 非法访问 一定会有 数组越位 行为！！！


int map[1005][1005];//也可把二维化为一维
int main() {
	int t,n,m,p;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&n,&m,&p);
		int x,y,val;
		int flag = 0,beyond = 0;
		for(int i = 0;i < n;i++)//初始化为0
			for(int j = 0;j < m;j++) map[i][j] = 0;
		while(p--) {
			cin>>x>>y>>val;
			//越位判断n和m不可省！！！
			if(x<0||x>=n||y<0||y>=m) beyond = 1;//数组越位
			if(x*m+y>n*m-1||x*m+y<0) flag = 1;//非法访问
			else {
				if(beyond) {//数组越位
					int ty = (x*m+y)%m;//x*m+y为总数
					int tx = (x*m+y)/m;
					map[tx][ty] = val;
				}
				else map[x][y] = val;
			}
		}
		//有非法访问就一定有数组越位，则先判断非法访问！！！
		if(flag) cout<<"Runtime error\n";
		else {//没有非法访问
			for(int i = 0;i < n;i++) {
				for(int j = 0;j < m;j++) {
					if(j!=0) cout<<' ';
					cout<<map[i][j];
				}
				cout<<"\n";
			}
			//beyond为1则为数组越位
			if(beyond) cout<<"Undefined Behaviour\n";
			else cout<<"Accepted\n";
		}
	}
	return 0;
}
