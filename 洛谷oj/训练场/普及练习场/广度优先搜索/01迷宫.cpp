#include<iostream>//ac
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 1010;
int n,m,vis[MAXN][MAXN],ans[MAXN][MAXN];
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};
char map[MAXN][MAXN];
struct node {
	int x,y;
};
int bfs(int x,int y) {
	if(ans[x][y]) return ans[x][y];//����Ѽ������ֱ�ӷ��ؽ��
	queue<node> q;
	q.push(node{x,y});
	vis[x][y] = 1;//�����ʼ��
	int sum = 1;//������һ��������
	node tmp;
	while(!q.empty()) {
		tmp = q.front();q.pop();
		for(int i = 0;i < 4;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			if(tx<0||tx>=n||ty<0||ty>=n) continue;//Խ��
			if(map[tx][ty]==map[tmp.x][tmp.y]) continue;//��λ��ͬ
			if(vis[tx][ty]) continue;//���߹�
			vis[tx][ty] = 1;
			sum++;
			q.push(node{tx,ty});
		}
	}
	q.push(node{x,y});//��ֹ�������������ظ�����
	vis[x][y] = 0;//��ʼ�����㣡����
	while(!q.empty()) {//�����������ӿ�
		tmp = q.front();q.pop();
		for(int i = 0;i < 4;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			if(tx<0||tx>=n||ty<0||ty>=n) continue;
			if(!vis[tx][ty]) continue;//����δ��ǿ�
			ans[tx][ty] = sum;//��С��һ����Ϊsum
			vis[tx][ty] = 0;//����
			q.push(node{tx,ty});
		}
	}
	return ans[x][y] = sum;//������ʼ����
}
int main() {
	int a,b;
	scanf("%d%d",&n,&m);
	for(int i = 0;i < n;i++) scanf("%s",map[i]);
	for(int i = 1;i <= m;i++) {
		scanf("%d%d",&a,&b);//��ʼλΪ0
		printf("%d\n",bfs(a-1,b-1));//��һλ
	}
	return 0;
}
