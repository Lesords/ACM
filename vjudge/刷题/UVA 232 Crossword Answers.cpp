#include<iostream>//ac
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int num[15][15],r,c;
char map[15][15];
bool f(int i,int j) {//判断是否是起始格
	if(i==0||j==0) return 1;
	if(map[i-1][j]=='*'||map[i][j-1]=='*') return 1;
	return 0;
}
int main() {
	int cas = 1;
	while(cin>>r&&r) {
		cin>>c;
		for(int i = 0;i < r;i++) cin>>map[i];
		if(cas!=1) cout<<endl;
		printf("puzzle #%d:\nAcross\n",cas++);
		int cnt = 1;
		memset(num,0,sizeof(num));//num记录起始块
		for(int i = 0;i < r;i++) {
			for(int j = 0;j < c;j++) {
				if(map[i][j]=='*') continue;//跳过黑块
				if(f(i,j)) {//判断是否为起始块
					if(!j||map[i][j-1]=='*') {//单词前不为白块
						printf("%3d.",cnt);
						for(int k = j;k < c;k++) {
							if(map[i][k]=='*') break;//到黑块截止
							cout<<map[i][k];
						}
						cout<<endl;
					}
					num[i][j] = cnt++;//起始块编号++
				}
			}
		}
		printf("Down\n");//类似（纵向找单词）
		for(int i = 0;i < r;i++) {
			for(int j = 0;j < c;j++) {
				if(map[i][j]=='*') continue;//跳过黑块
				if(num[i][j]&&(!i||map[i-1][j]=='*')) {
					printf("%3d.",num[i][j]);
					for(int k = i;k < r;k++) {
						if(map[k][j]=='*') break;
						cout<<map[k][j];
					}
					cout<<endl;
				}
			}
		}
	}
	return 0;
}
