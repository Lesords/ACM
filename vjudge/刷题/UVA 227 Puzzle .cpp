#include<iostream>//ac
#include<cstdio>
#include<cstring>
using namespace std;
char a[8][8];
int bx,by,flag;
void swap(int x,int y) {//移动
	if(x<1||x>5||y<1||y>5) {//越界,非法操作
		flag = 1;
		return ;
	}
	a[bx][by] = a[x][y];
	a[x][y] = ' ';
	bx = x,by = y;//更新空格位置
}
int main() {
	int cnt = 1;
	while(1) {
		for(int i = 1;i <= 5;i++) {//空格可能出现在第一行
			for(int j = 1;j <= 5;j++) {
				scanf("%c",&a[i][j]);
				if(a[i][j]==' ') bx = i,by = j;
				if(a[1][1]=='Z') return 0;
			}
			getchar();//每行末尾的回车字符 
		}
		char op;
		flag = 0;
		while(1) {
			scanf("%c",&op);
			if(op=='0') break;
			if(op=='\n'||flag) continue;//回车字符或越界操作
			switch(op) {
				case 'A':swap(bx-1,by);break;//空格上
				case 'B':swap(bx+1,by);break;//空格下
				case 'L':swap(bx,by-1);break;//空格左
				case 'R':swap(bx,by+1);break;//空格右
			}
		}
		getchar();//操作0末尾的回车字符
		if(cnt!=1) printf("\n");
		printf("Puzzle #%d:\n",cnt++);
		if(flag) {//越界操作
			printf("This puzzle has no final configuration.\n");
			continue;
		} 
		for(int i = 1;i <= 5;i++) {
			for(int j = 1;j <= 5 ;j++) {
				if(j!=1) printf(" ");
				printf("%c",a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
