#include<iostream>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
struct box_move {//����
	int x,y,wx,wy,step;//x y Ϊ���ӵ�ǰλ�� wx wy Ϊ���˵�ǰλ��
	friend bool operator <(box_move a,box_move b) {
		return a.step>b.step;
	}
};
struct work {//����
	int x,y;//ֻ��Ҫ�ж��Ƿ���Ե���ָ��λ�ã�����step 
};
int map[8][8],book[8][8],vis[8][8],n,m,ex,ey;
int bfs_move(int x,int y,int nx,int ny) {//x,yΪ���˹���Ŀ��λ��
	queue<work> man;
	man.push(work{nx,ny});//���˹���ʼλ��
	int next[4][2]={1,0,0,1,-1,0,0,-1};//�ĸ����� 
	while(!man.empty()) {
		work tmp;
		tmp = man.front();man.pop();
		if(tmp.x==x&&tmp.y==y) return false;//���Ե��� 
		for(int i=0;i<4;i++) {
			int tx = tmp.x + next[i][0];
			int ty = tmp.y + next[i][1];
			if(tx<1||tx>m||ty<1||ty>n) continue;//Խ�� 
			if(map[tx][ty]==-1||book[tx][ty]) continue;//ǽ�����߹� 
			man.push(work{tx,ty});
			book[tx][ty]=1;//����߹��ĸ��� 
		}
	}
	return true;
}
int bfs(int sx,int sy,int wx,int wy) {//����
	priority_queue<box_move> q;
	q.push(box_move{sx,sy,wx,wy,0});
	int next[4][2]={1,0,0,1,-1,0,0,-1};
	while(!q.empty()) {
		box_move tmp;
		tmp = q.top();q.pop();
		if(tmp.x == ex && tmp.y == ey) 
			return tmp.step;//���ӵ����յ�λ��
		for(int i=0;i<4;i++) {
			int tx = tmp.x + next[i][0];
			int ty = tmp.y + next[i][1];
			int man_x = tmp.x - next[i][0];//����Ŀ�ĵ�
			int man_y = tmp.y - next[i][1];
			if(tx<1||tx>m||ty<1||ty>n) continue;//Խ��
			if(map[tx][ty]==-1||vis[tx][ty]>2) continue;//�ص㣡����
			if(map[man_x][man_y]==-1) continue;//���˹�Ŀ�ĵ�Ϊǽ
			memset(book,0,sizeof(book));//book������ǰ��˹��߹��ĸ���
			book[tmp.x][tmp.y]=1;//������ӵ�λ��
			if(bfs_move(man_x,man_y,tmp.wx,tmp.wy)) continue;//�ж��Ƿ���Ե���
			book[tmp.x][tmp.y]=0;//��ԭ 
			q.push(box_move{tx,ty,man_x,man_y,tmp.step+1});
			vis[tx][ty]++;
		}
	}
	return -1;
}
int main() {
	int T;
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--) {
		cin>>m>>n;//m��n��
		int tmp,sx,sy,wx,wy;
		memset(vis,0,sizeof(vis));//vis������������߹��ĸ���
		for(int i=1;i<=m;i++) {
			for(int j=1;j<=n;j++) {
				cin>>tmp;
				map[i][j]=0;
				if(tmp==1) map[i][j]=-1;
				else if(tmp==2) sx=i,sy=j;//�������λ�� 
				else if(tmp==3) ex=i,ey=j;//�����յ�λ�� 
				else if(tmp==4) wx=i,wy=j;//���˹���ʼλ�� 
			}
		}
		cout<<bfs(sx,sy,wx,wy)<<endl;
	}
	return 0;
}
/*
4
5 5
3 0 1 0 0
1 0 1 4 0
0 0 1 0 0
1 0 2 0 0
0 0 0 0 0
5 5
0 3 0 0 0
1 0 1 4 0
0 0 1 0 0
1 0 2 0 0
0 0 0 0 0
5 5
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
1 1 2 1 1
4 0 3 0 0
7 4
0 0 0 0
0 0 1 0
0 2 0 3
1 4 1 0
1 0 1 0
1 0 1 0
1 0 0 0
��Ӧ���ǣ�-1 4 5 2
*/ 
