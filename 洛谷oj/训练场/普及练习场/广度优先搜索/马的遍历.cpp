#include<iostream>//ac
#include<cstdio>
#include<queue>
using namespace std;
const int MAXN = 405;
int map[MAXN][MAXN],vis[MAXN][MAXN];
int n,m,s,e;//�������8������
int nextt[8][2] = {1,2,2,1,1,-2,2,-1,-2,1,-1,2,-1,-2,-2,-1};
struct node {
	int x,y,step;
};
void bfs(int x,int y) {
	queue<node> q;
	q.push(node{x,y,0});//��㲽��Ϊ0
	node tmp;
	while(!q.empty()) {
		tmp = q.front();q.pop();
		for(int i = 0;i < 8;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			if(tx<1||tx>n||ty<1||ty>m) continue;//Խ��
			if(vis[tx][ty]) continue;//���߹�
			vis[tx][ty] = 1;//��ǵ�ǰλ��
			map[tx][ty] = tmp.step+1;//���浱ǰ����
			q.push(node{tx,ty,tmp.step+1});
		}
	}
}
int main() {
	cin>>n>>m>>s>>e;
	bfs(s,e);//�����bfs
	for(int i = 1;i <= n;i++) {
		for(int j = 1;j <= m;j++) {
			if(i==s&&j==e) cout<<"0    ";//���Ϊ0�����ܵ�Ϊ-1
			else printf("%-5d",(map[i][j]?map[i][j]:-1));
		}
		cout<<endl;
	}
	return 0;
}
