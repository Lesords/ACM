#include<iostream>//ac
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
struct node{
	int pos,step;
	friend bool operator < (node a,node b) {
		//����Ϊ�٣�������Զ
		if(a.step!=b.step) return a.step > b.step;
		else return a.pos < b.pos;
	}
};
const int MAXN = 200005;//������Χ����Ϊ��*2����
int n,k;
int vis[MAXN];
void bfs() {
	priority_queue<node> q;
	q.push(node{n,0});//���
	node tmp;
	while(!q.empty()) {
		tmp = q.top(),q.pop();
		if(tmp.pos==k) {//����Ŀ�ĵ�
			printf("%d",tmp.step);
			return;
		}
		for(int i = -1;i <= 1;i+=2) {//������������
			int tx = tmp.pos+i;
			if(tx<0||vis[tx]) continue;
			//tx����Ϊ����Ҳ�����ظ�����
			vis[tx] = tmp.step+1;//��¼Ϊ����
			q.push(node{tx,tmp.step+1});
		}
		if(tmp.pos>k||vis[tmp.pos*2]) continue;
		//����k���ѷ��ʶ���Ҫ����
		q.push(node{tmp.pos*2,tmp.step+1});
		vis[tmp.pos*2] = tmp.step+1;
	}
}
int main() {
	scanf("%d%d",&n,&k);
	if(n>=k) printf("%d",n-k);//����kʱ��ֻ��һ������
	else bfs();
	return 0;
}
