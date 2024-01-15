#include<iostream>//ac
#include<queue> 
using namespace std;
struct node{
	int x,y;
};
int n,map[35][35],vis[35][35];
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};
int bfs(int x,int y) {
	int flag = 1;//1Ϊ�պ�Ȧ��0Ϊ�Ǳպ�
	queue<node> q;
	q.push(node{x,y});
	node tmp;
	while(!q.empty()) {
		tmp = q.front();q.pop();
		for(int i = 0;i < 4;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			if(tx<1||tx>n||ty<1||ty>n) {//Խ��
				flag = 0;continue;//˵�����Ǳպ�Ȧ
			}//���Ǳպ�ȦҲҪ��ǣ������ظ��жϣ�����
			if(map[tx][ty]||vis[tx][ty]) continue;
			vis[tx][ty] = 1;//����ѱ�������
			q.push(node{tx,ty});
		}
	}
	return flag;
}
void change(int x,int y) {//dfs
	map[x][y] = 2;//��ֵΪ2
	for(int i = 0;i < 4;i++) {
		int tx = x + nextt[i][0];
		int ty = y + nextt[i][1];
		if(map[tx][ty]) continue;//�����պ�Ȧ���Ѹ�ֵ��
		change(tx,ty);//�ݹ�
	}
}
int main() {
	int flag = 0;
	cin>>n; 
	for(int i = 1;i <= n;i++) 
		for(int j = 1;j <= n;j++) cin>>map[i][j];
	for(int i = 1;i <= n && !flag;i++) {
		for(int j = 1;j <= n;j++) {
			//���� ���жϹ� �� �պ�Ȧ����1��
			if(map[i][j]||vis[i][j]) continue;
			if(bfs(i,j)) {//�ж��Ǳպ�Ȧ
				change(i,j);//���ǣ��򽫱պ�Ȧ�����ָ�Ϊ2
				flag = 1;break;//�˳�ѭ��
			}
		}
	}
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= n;j++) {
			if(j!=1) cout<<' ';
			cout<<map[i][j];
		}
		cout<<endl;
	}
	return 0;
}
