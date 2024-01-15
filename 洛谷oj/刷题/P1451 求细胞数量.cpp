#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺dfs����ͨ��

int n,m,vis[105][105],ans;
int nextt[4][2] = {0,1,1,0,0,-1,-1,0};//�ĸ�����
char a[105][105];
void dfs(int x,int y) {
    vis[x][y] = 1;//���
    for(int i = 0;i < 4;i++) {
        int tx = x + nextt[i][0];
        int ty = y + nextt[i][1];
        if(tx<1||tx>n||ty<1||ty>m) continue;//Խ��
        if(a[tx][ty]=='0'||vis[tx][ty]) continue;//��ϸ�����ѷ���
        vis[tx][ty] = 1;//��ǵ�ǰ��
        dfs(tx,ty);//����dfs
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) cin>>a[i][j];
    }
    for(int i = 1;i <= n;i++) {//���е����dfs
        for(int j = 1;j <= m;j++) {
            //��Ϊϸ�����ѷ���
            if(a[i][j]=='0'||vis[i][j]) continue;
            dfs(i,j);ans++;//��δ���ʵ�ϸ��
        }
    }
    cout<<ans<<endl;
    return 0;
}
