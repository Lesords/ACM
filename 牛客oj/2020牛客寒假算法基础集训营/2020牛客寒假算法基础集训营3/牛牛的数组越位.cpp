#include<iostream>//ac
#include<cstdio>
using namespace std;

//��⣺��Ҫע���������Խλ��Ϊ��ֻ�Ǹ������г���Χ
//���в��� �Ƿ����� һ������ ����Խλ ��Ϊ������


int map[1005][1005];//Ҳ�ɰѶ�ά��Ϊһά
int main() {
	int t,n,m,p;
	scanf("%d",&t);
	while(t--) {
		scanf("%d%d%d",&n,&m,&p);
		int x,y,val;
		int flag = 0,beyond = 0;
		for(int i = 0;i < n;i++)//��ʼ��Ϊ0
			for(int j = 0;j < m;j++) map[i][j] = 0;
		while(p--) {
			cin>>x>>y>>val;
			//Խλ�ж�n��m����ʡ������
			if(x<0||x>=n||y<0||y>=m) beyond = 1;//����Խλ
			if(x*m+y>n*m-1||x*m+y<0) flag = 1;//�Ƿ�����
			else {
				if(beyond) {//����Խλ
					int ty = (x*m+y)%m;//x*m+yΪ����
					int tx = (x*m+y)/m;
					map[tx][ty] = val;
				}
				else map[x][y] = val;
			}
		}
		//�зǷ����ʾ�һ��������Խλ�������жϷǷ����ʣ�����
		if(flag) cout<<"Runtime error\n";
		else {//û�зǷ�����
			for(int i = 0;i < n;i++) {
				for(int j = 0;j < m;j++) {
					if(j!=0) cout<<' ';
					cout<<map[i][j];
				}
				cout<<"\n";
			}
			//beyondΪ1��Ϊ����Խλ
			if(beyond) cout<<"Undefined Behaviour\n";
			else cout<<"Accepted\n";
		}
	}
	return 0;
}
