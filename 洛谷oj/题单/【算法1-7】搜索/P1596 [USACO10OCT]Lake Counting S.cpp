#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺dfs����ͨ��

char map[105][105];
bool vis[105][105];//��¼�Ƿ���ʹ�
int nextt[8][2] = {1,0,1,1,0,1,-1,1,-1,0,-1,-1,0,-1,1,-1};//�˸�����
int n,m,ans;
void dfs(int x,int y) {//(x,y)��ʼ������ͨ��
    for(int i = 0;i < 8;i++) {
        int tx = x + nextt[i][0];
        int ty = y + nextt[i][1];
        if(tx<1||tx>n||ty<1||ty>m) continue;//Խ��
        if(map[tx][ty]=='.'||vis[tx][ty]) continue;//�յĻ��ѷ���
        vis[tx][ty] = 1;//���
        dfs(tx,ty);//����dfs
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++)
        for(int j = 1;j <= m;j++) cin>>map[i][j];
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(map[i][j]=='.'||vis[i][j]) continue;//�յĻ��ѷ��ʣ�����
            vis[i][j] = 1;//������
            dfs(i,j);ans++;//����һ���µĿ�
        }
    }
    cout<<ans<<endl;//������
    return 0;
}
