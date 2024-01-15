#include<iostream>//ac
#include<set>
using namespace std;
char map[105][105];
char op[10] = {'y','i','z','h','o','n','g'};//�����Ӧ���ַ�
int book[105][105],n;
//�˸�����
int nextt[8][2] = {0,1,1,1,1,0,1,-1,0,-1,-1,-1,-1,0,0,-1};
struct node{
	int x,y;
}trace[10];//����·������
void dfs(int x,int y,int dir,int step) {
	//step������һ������2��ʼ�����Զ�Ӧ���� -1
	trace[step-1].x = x,trace[step-1].y = y;//����·������
	if(step==8) {//��������ʱ
		for(int i = 1;i <= 7;i++) {
			book[trace[i].x][trace[i].y] = 1;
		}//·���ϵ����궼���Ϊ1
		return ;
	}
	int tx = x + nextt[dir][0];
	int ty = y + nextt[dir][1];
	if(tx<0||tx>=n||ty<0||ty>=n) return;//Խ��
	//op�����0��ʼ������step�� -1
	if(map[tx][ty]!=op[step-1]) return;//���Ӧ�ַ���һ��
	dfs(tx,ty,dir,step+1);
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 0;i < n;i++) cin>>map[i];
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {
			if(book[i][j]) continue;//�ѱ�ǹ�
			if(map[i][j]=='y') {//y��ͷ�ű���
				for(int k = 0;k <= 7;k++) dfs(i,j,k,2);//��2λ
			}//����8������
		}
	}
	for(int i = 0;i < n;i++) {
		for(int j = 0;j < n;j++) {//û�б�ǵ�Ϊ *
			cout<<(book[i][j]?map[i][j]:'*');
		}
		cout<<endl;
	}
	return 0;
}
