#include<iostream>//ac
#include<cstdio>
#include<cstring>
using namespace std;
char map[11][16],color;
int vis[11][16],maxx,x,y,num;
int nextt[4][2] = {1,0,0,1,-1,0,0,-1};
void dfs(int x, int y, char ch) {//寻找区间块数量
	for(int i = 0;i < 4;i++) {
		int tx = x + nextt[i][0];
		int ty = y + nextt[i][1];
		if(tx<1||tx>10||ty<0||ty>14) continue;
		if(vis[tx][ty]||map[tx][ty]!=ch) continue;
		vis[tx][ty] = 1;
		num++;//区间块数量
		dfs(tx,ty,ch);//ch为棋子颜色
	}
}
void find_all() {//遍历整个棋板，寻找最大块
	memset(vis,0,sizeof(vis));//初始化标记数组
	for(int i = 0;i < 15;i++) {//先左（遍历列）
		for(int j = 1;j <= 10;j++) {//先下（遍历行）
			if(vis[j][i]||map[j][i]==' ') continue;
			vis[j][i] = num = 1;
			dfs(j,i,map[j][i]);//寻找区间块
			if(num>maxx) {
				maxx = num;//更新最大值
				x = j, y = i;//更新坐标
				color = map[x][y];//更新颜色
			}
		}
	}
}
int rest_num(int flag) {
	int rest = 0;
	for(int i = 1;i <= 10;i++) {
		for(int j = 0;j < 15;j++) {
			if(map[i][j] != ' ') {
				if(flag) rest++;//为1时，判断数量
				else return 1;//为0时，只判断是否为空
			}
		}
	}
	return rest;
}
void destroy(int x,int y) {
	map[x][y] = ' ';//删除（每次递归到的都需要删除）
	for(int i = 0;i < 4;i++) {
		int tx = x + nextt[i][0];
		int ty = y + nextt[i][1];
		if(tx<1||tx>10||ty<0||ty>14) continue;//越界
		if(map[tx][ty] != color) continue;//不是特定颜色
		destroy(tx,ty);//递归
	}
}
void shift() {//调整棋盘
	char tmp[20];
	int cnt;
	//下降合并 
	for(int i = 0;i < 15;i++) {//遍历列
		memset(tmp,0,sizeof(tmp));
		cnt = 1;//记录当前列还有多少个棋子
		for(int j = 1;j <= 10;j++) {//遍历行
			if(map[j][i] == ' ') continue;
			tmp[cnt++] = map[j][i];//保存非空字符数组
		}
		for(int j = 1;j < cnt;j++) map[j][i] = tmp[j];
		for(int j = cnt;j <= 10;j++) map[j][i] = ' ';
	}
	//靠左合并
	for(int i = 14;i >= 0;i--) {//遍历列
		int flag = 0;
		for(int j = 1;j <= 10;j++) {//判断是否为空列
			if(map[j][i] == ' ') continue;
			else flag = 1;//寻找空列
		}
		if(!flag) {//当前为空列
			for(int j = i;j <= 14;j++) {
				for(int k = 1;k <= 10;k++) {
					map[k][j] = map[k][j+1];//向左移
				}
			}
			for(int k = 1;k <= 10;k++) map[k][14] = ' ';//最右列清空
		}
	}
}
int main() {
	int t;
	scanf("%d",&t);
	for(int i = 1;i <= t;i++) {
		for(int j = 10;j >= 1;j--) {
			scanf("%s",map[j]);	//列起始点为0
		}
		if(i!=t) getchar();		//处理输入的空行
		printf("Game %d:\n\n",i);
		int cnt = 1,point = 0,sum = 0;
		while(rest_num(0)) {
			maxx = 1;
			find_all();			//寻找最大块
			if(maxx==1) break;  //没有满足条件的最大块
			destroy(x,y);		//清除最大块
			shift();			//调整棋盘
			point = (maxx-2)*(maxx-2);//当前分数
			sum += point;       //总分数
			printf("Move %d at (%d,%d): removed %d balls",cnt++,x,y+1,maxx);
			printf(" of color %c, got %d points.\n",color,point);
		}
		int final = rest_num(1);//剩余数量
		if(!final) sum += 1000;	//全清空奖励1000
		printf("Final score: %d, with %d balls remaining.\n",sum,final);
		if(i!=t) printf("\n");
	}
	return 0;
}
