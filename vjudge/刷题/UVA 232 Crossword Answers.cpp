#include<iostream>//ac
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int num[15][15],r,c;
char map[15][15];
bool f(int i,int j) {//�ж��Ƿ�����ʼ��
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
		memset(num,0,sizeof(num));//num��¼��ʼ��
		for(int i = 0;i < r;i++) {
			for(int j = 0;j < c;j++) {
				if(map[i][j]=='*') continue;//�����ڿ�
				if(f(i,j)) {//�ж��Ƿ�Ϊ��ʼ��
					if(!j||map[i][j-1]=='*') {//����ǰ��Ϊ�׿�
						printf("%3d.",cnt);
						for(int k = j;k < c;k++) {
							if(map[i][k]=='*') break;//���ڿ��ֹ
							cout<<map[i][k];
						}
						cout<<endl;
					}
					num[i][j] = cnt++;//��ʼ����++
				}
			}
		}
		printf("Down\n");//���ƣ������ҵ��ʣ�
		for(int i = 0;i < r;i++) {
			for(int j = 0;j < c;j++) {
				if(map[i][j]=='*') continue;//�����ڿ�
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
