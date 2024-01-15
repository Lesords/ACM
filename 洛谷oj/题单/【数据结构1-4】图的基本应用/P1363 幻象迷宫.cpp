#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺���Թ�����Χ��ɢ������ƴ����������ô��������Զ���������Ϊ
//�ظ�����һ���㣨��Ӧԭ�Թ������������η��ʵ�ʵ�����겻һ��
//�����ظ�����һ���㣬˵����������ѭ�����·����ֱ������Զ
//����ֱ�Ӵ���㿪ʼdfs������vis����¼��ǰ���Ƿ��߹��Լ��߹��ĵ��ʵ������

const int MAXN = 1505;
char s[MAXN][MAXN];
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};                      //�ĸ�����
int n,m,flag,vis[MAXN][MAXN][3];                            //flag��¼�Ƿ���Ե�������Զ
//vis[x][y][0]Ϊ��(x,y)�Ƿ������
//vis[x][y][1]Ϊ���ʵ�(x,y)��ʵ������x
//vis[x][y][2]Ϊ���ʵ�(x,y)��ʵ������y
void dfs(int x,int y,int lx,int ly) {//(x,y)Ϊ��ԭ�Թ��ϵĶ�Ӧ���꣬(lx,ly)Ϊʵ������
    if(flag) return;                                        //ȷ�������ֱ�ӷ���
    //��ǰʵ���������һ�η���ʱ��ʵ������Աȣ������ǵ�ǰ�����ʵ������Աȣ�����
    //��ǰλ���ѷ��ʹ�������һ������ֵ����һ������ͬ
    if(vis[x][y][0]&&(vis[x][y][1]!=lx||vis[x][y][2]!=ly)) {
        flag = 1;return;
    }
    vis[x][y][0] = 1;                                       //��ǵ�ǰ��
    vis[x][y][1] = lx,vis[x][y][2] = ly;                    //��¼ʵ������
    for(int i = 0;i < 4;i++) {
        int tx = (x+nextt[i][0]+n)%n;                       //��Ӧԭ�Թ������꣬��ȡģ
        int ty = (y+nextt[i][1]+m)%m;
        int mx = lx + nextt[i][0];                          //ʵ������
        int my = ly + nextt[i][1];
        if(s[tx][ty]=='#') continue;                        //����ǽ
        //��ǰ��δ���������߱�������ʵ�����겻��ͬ������Լ�������
        if(!vis[tx][ty][0]||vis[tx][ty][1]!=mx||vis[tx][ty][2]!=my) {
            dfs(tx,ty,mx,my);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    while(cin>>n>>m) {
        memset(vis,0,sizeof(vis));                          //��ʼ��Ϊ0
        flag = 0;
        int sx,sy;
        for(int i = 0;i < n;i++) {                          //����ȡģ�����0��ʼ��¼
            for(int j = 0;j < m;j++) {
                cin>>s[i][j];
                if(s[i][j]=='S') {                          //��¼�������
                    sx = i,sy = j;
                }
            }
        }
        dfs(sx,sy,sx,sy);
        if(flag) cout<<"Yes\n";
        else cout<<"No\n";
    }
    return 0;
}
