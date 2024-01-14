#include<iostream>//ac  (G++ ac)
#include<cstdio>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int x,y,step;
};
int a[6][6],vis[6][6],cnt;
int nextt[4][2] = {1,0,0,1,-1,0,0,-1};
void bfs(int x,int y) {//Ѱ�����·�������½ǣ�������߹�λ��
	queue<node> q;
	q.push(node{x,y,0});//C++��֧�ָ�д��
	node tmp;
	while(!q.empty()) {
		tmp = q.front();
		q.pop();
		if(tmp.x==4&&tmp.y==4) {
			cnt = tmp.step;break;//cntΪ��̲���
		}
		for(int i = 0;i < 4;i++) {
			int tx = tmp.x + nextt[i][0];
			int ty = tmp.y + nextt[i][1];
			if(tx<0||tx>4||ty<0||ty>4) continue;//�߽�
			if(!tx&!ty||vis[tx][ty]||a[tx][ty]) continue;
			//��ʼ�㣬ǽ�����߹�
			vis[tx][ty] = tmp.step+1;//��ǵ�ǰλ�����貽��
			q.push(node{tx,ty,tmp.step+1});
		}
	}
}
void solve(int x,int y,int step) {//���յ㵽��㷴��Ѱ��
	stack<node> ans;//ջ����ȳ�������Ѱ��·��
	ans.push(node{x,y,step});//����յ�
	while(step) {//Ѱ��step-1���ڵ�λ�ã���(x,y)ǰһ��λ��
		for(int i = 0;i < 4;i++) {
			int tx = x + nextt[i][0];
			int ty = y + nextt[i][1];
			if(tx<0||tx>4||ty<0||ty>4) continue;//�߽�
			if(a[tx][ty]) continue;//ǽ
			//�����ǰλ��Ϊǰһ��ʱ��vis[tx][ty] = step-1
			if(vis[tx][ty]!=step-1) continue;//���������
			x = tx,y = ty;//���µ�ǰλ��
			ans.push(node{tx,ty,--step});//��ջ���޸�step
		}
	}
	node tmp;
	while(ans.size()) {//��ջ������ȫ���������
		tmp = ans.top(),ans.pop();
		printf("(%d, %d)\n",tmp.x,tmp.y);
	}
}
int main() {
	for(int i = 0;i < 5;i++)
		for(int j = 0;j < 5;j++)
			scanf("%d",&a[i][j]);
	bfs(0,0);//Ѱ�����·��
	solve(4,4,cnt);//����Ѱ�ң����·��
	return 0;
}
