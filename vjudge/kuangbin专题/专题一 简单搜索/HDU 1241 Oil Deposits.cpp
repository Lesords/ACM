#include<iostream>//ac dfs����ͨ��
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 105;
int n,m,vis[MAXN][MAXN];
int nextt[8][2] = {0,1,0,-1,1,0,-1,0,1,1,-1,1,1,-1,-1,-1};//8������
char s[MAXN][MAXN];
void dfs(int x,int y) {//��������� (x,y) ��ͨ��λ��
    vis[x][y] = 1;
    for(int i = 0;i < 8;i++) {//8������
        int tx = x+nextt[i][0];
        int ty = y+nextt[i][1];
        if(tx<1||tx>n||ty<1||ty>m) continue;//Խ��
        if(vis[tx][ty]||s[tx][ty]=='*') continue;//�ѱ�ǻ�Ϊ��
        dfs(tx,ty);
    }
}
int main() {
    while(cin>>n>>m&&n+m) {
        for(int i = 1;i <= n;i++) cin>>s[i]+1;
        memset(vis,0,sizeof(vis));
        int ans = 0;//��ʼ��
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= m;j++) {//�����е�Ϊ���
                if(vis[i][j]||s[i][j]=='*') continue;//�����ѱ�ǻ�Ϊ�յĵ�
                dfs(i,j);
                ans++;//ͳ�ƽ��
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
