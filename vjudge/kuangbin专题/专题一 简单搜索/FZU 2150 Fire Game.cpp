#include<iostream>//ac
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺����dfs������ͨ�飬С��2�ĺʹ���2�Ķ�����
//ʣ���ö�����е���������bfs�������ȼ�����ֵ

struct node{
    int x,y,step;
    friend bool operator < (node a,node b) {
        return a.step > b.step;//���Ȳ����ٵ�
    }
};
char s[15][15];
int n,m,vis[15][15];
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};//�ĸ�����
void dfs(int x,int y) {//�����м�����ͨ��
    vis[x][y] = 1;//��ǵ�ǰ��
    for(int i = 0;i < 4;i++) {
        int tx = x+nextt[i][0];
        int ty = y+nextt[i][1];
        if(tx<1||tx>n||ty<1||ty>m) continue;//Խ��
        if(s[tx][ty]=='.'||vis[tx][ty]) continue;//�յػ��ѱ��
        vis[tx][ty] = 1;//���ָ���
        dfs(tx,ty);
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;cin>>t;
    for(int cas = 1;cas <= t;cas++) {
        cin>>n>>m;
        for(int i = 1;i <= n;i++) cin>>s[i]+1;
        vector<node> grass;//��¼���вݵص�λ��
        int num = 0;
        memset(vis,0,sizeof(vis));
        for(int i = 1;i <= n;i++) {//��¼�ݵص�ʱ�����һ�������ͨ��
            for(int j = 1;j <= m;j++) {
                if(s[i][j]=='#') {
                    if(vis[i][j]==0) {
                        dfs(i,j);num++;
                    }
                    node tmp = {i,j,0};
                    grass.push_back(tmp);
                }
            }
        }
        if(num>2) {//����������ͨ�鼴�޽�
            cout<<"Case "<<cas<<": "<<-1<<"\n";
            continue;
        }
        if(grass.size()<=2) {//��������������������
            cout<<"Case "<<cas<<": "<<0<<"\n";
            continue;
        }
        int ans = INF;//��¼���Ĵ�
        for(int i = 0;i < grass.size();i++) {//ö�����е�������
            for(int j = i+1;j < grass.size();j++) {
                memset(vis,0,sizeof(vis));
                priority_queue<node> q;
                int cnt = 2;//��ʼ������
                q.push(grass[i]);
                q.push(grass[j]);
                vis[grass[i].x][grass[i].y] = 1;
                vis[grass[j].x][grass[j].y] = 1;//���������
                while(!q.empty()) {
                    node tmp = q.top();q.pop();
                    for(int i = 0;i < 4;i++) {
                        int tx = tmp.x+nextt[i][0];
                        int ty = tmp.y+nextt[i][1];
                        if(tx<1||tx>n||ty<1||ty>m) continue;//Խ��
                        if(s[tx][ty]=='.'||vis[tx][ty]) continue;//�յػ��ѱ��
                        vis[tx][ty] = 1;//��ǵ�ǰ��
                        cnt++;//��¼�Ѿ�ȼ�յ�����
                        if(cnt==grass.size()) {//��������ܲݵص���������´�
                            ans = min(ans,tmp.step+1);
                        }
                        node tt = {tx,ty,tmp.step+1};
                        q.push(tt);//���
                    }
                }
            }
        }
        //��Ҫ�ж��Ƿ�ΪINF������
        cout<<"Case "<<cas<<": "<<(ans==INF?-1:ans)<<"\n";
    }
    return 0;
}
