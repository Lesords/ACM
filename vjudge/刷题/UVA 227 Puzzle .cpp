#include<iostream>//ac
#include<cstdio>
#include<cstring>
using namespace std;
char a[8][8];
int bx,by,flag;
void swap(int x,int y) {//�ƶ�
	if(x<1||x>5||y<1||y>5) {//Խ��,�Ƿ�����
		flag = 1;
		return ;
	}
	a[bx][by] = a[x][y];
	a[x][y] = ' ';
	bx = x,by = y;//���¿ո�λ��
}
int main() {
	int cnt = 1;
	while(1) {
		for(int i = 1;i <= 5;i++) {//�ո���ܳ����ڵ�һ��
			for(int j = 1;j <= 5;j++) {
				scanf("%c",&a[i][j]);
				if(a[i][j]==' ') bx = i,by = j;
				if(a[1][1]=='Z') return 0;
			}
			getchar();//ÿ��ĩβ�Ļس��ַ� 
		}
		char op;
		flag = 0;
		while(1) {
			scanf("%c",&op);
			if(op=='0') break;
			if(op=='\n'||flag) continue;//�س��ַ���Խ�����
			switch(op) {
				case 'A':swap(bx-1,by);break;//�ո���
				case 'B':swap(bx+1,by);break;//�ո���
				case 'L':swap(bx,by-1);break;//�ո���
				case 'R':swap(bx,by+1);break;//�ո���
			}
		}
		getchar();//����0ĩβ�Ļس��ַ�
		if(cnt!=1) printf("\n");
		printf("Puzzle #%d:\n",cnt++);
		if(flag) {//Խ�����
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
