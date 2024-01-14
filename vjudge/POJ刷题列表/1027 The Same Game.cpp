#include<iostream>//ac
#include<cstdio>
#include<cstring>
using namespace std;
char map[11][16],color;
int vis[11][16],maxx,x,y,num;
int nextt[4][2] = {1,0,0,1,-1,0,0,-1};
void dfs(int x, int y, char ch) {//Ѱ�����������
	for(int i = 0;i < 4;i++) {
		int tx = x + nextt[i][0];
		int ty = y + nextt[i][1];
		if(tx<1||tx>10||ty<0||ty>14) continue;
		if(vis[tx][ty]||map[tx][ty]!=ch) continue;
		vis[tx][ty] = 1;
		num++;//���������
		dfs(tx,ty,ch);//chΪ������ɫ
	}
}
void find_all() {//����������壬Ѱ������
	memset(vis,0,sizeof(vis));//��ʼ���������
	for(int i = 0;i < 15;i++) {//���󣨱����У�
		for(int j = 1;j <= 10;j++) {//���£������У�
			if(vis[j][i]||map[j][i]==' ') continue;
			vis[j][i] = num = 1;
			dfs(j,i,map[j][i]);//Ѱ�������
			if(num>maxx) {
				maxx = num;//�������ֵ
				x = j, y = i;//��������
				color = map[x][y];//������ɫ
			}
		}
	}
}
int rest_num(int flag) {
	int rest = 0;
	for(int i = 1;i <= 10;i++) {
		for(int j = 0;j < 15;j++) {
			if(map[i][j] != ' ') {
				if(flag) rest++;//Ϊ1ʱ���ж�����
				else return 1;//Ϊ0ʱ��ֻ�ж��Ƿ�Ϊ��
			}
		}
	}
	return rest;
}
void destroy(int x,int y) {
	map[x][y] = ' ';//ɾ����ÿ�εݹ鵽�Ķ���Ҫɾ����
	for(int i = 0;i < 4;i++) {
		int tx = x + nextt[i][0];
		int ty = y + nextt[i][1];
		if(tx<1||tx>10||ty<0||ty>14) continue;//Խ��
		if(map[tx][ty] != color) continue;//�����ض���ɫ
		destroy(tx,ty);//�ݹ�
	}
}
void shift() {//��������
	char tmp[20];
	int cnt;
	//�½��ϲ� 
	for(int i = 0;i < 15;i++) {//������
		memset(tmp,0,sizeof(tmp));
		cnt = 1;//��¼��ǰ�л��ж��ٸ�����
		for(int j = 1;j <= 10;j++) {//������
			if(map[j][i] == ' ') continue;
			tmp[cnt++] = map[j][i];//����ǿ��ַ�����
		}
		for(int j = 1;j < cnt;j++) map[j][i] = tmp[j];
		for(int j = cnt;j <= 10;j++) map[j][i] = ' ';
	}
	//����ϲ�
	for(int i = 14;i >= 0;i--) {//������
		int flag = 0;
		for(int j = 1;j <= 10;j++) {//�ж��Ƿ�Ϊ����
			if(map[j][i] == ' ') continue;
			else flag = 1;//Ѱ�ҿ���
		}
		if(!flag) {//��ǰΪ����
			for(int j = i;j <= 14;j++) {
				for(int k = 1;k <= 10;k++) {
					map[k][j] = map[k][j+1];//������
				}
			}
			for(int k = 1;k <= 10;k++) map[k][14] = ' ';//���������
		}
	}
}
int main() {
	int t;
	scanf("%d",&t);
	for(int i = 1;i <= t;i++) {
		for(int j = 10;j >= 1;j--) {
			scanf("%s",map[j]);	//����ʼ��Ϊ0
		}
		if(i!=t) getchar();		//��������Ŀ���
		printf("Game %d:\n\n",i);
		int cnt = 1,point = 0,sum = 0;
		while(rest_num(0)) {
			maxx = 1;
			find_all();			//Ѱ������
			if(maxx==1) break;  //û����������������
			destroy(x,y);		//�������
			shift();			//��������
			point = (maxx-2)*(maxx-2);//��ǰ����
			sum += point;       //�ܷ���
			printf("Move %d at (%d,%d): removed %d balls",cnt++,x,y+1,maxx);
			printf(" of color %c, got %d points.\n",color,point);
		}
		int final = rest_num(1);//ʣ������
		if(!final) sum += 1000;	//ȫ��ս���1000
		printf("Final score: %d, with %d balls remaining.\n",sum,final);
		if(i!=t) printf("\n");
	}
	return 0;
}
