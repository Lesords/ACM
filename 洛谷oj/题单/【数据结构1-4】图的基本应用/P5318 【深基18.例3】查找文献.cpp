#include<iostream>//ac
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺vector��ͼ��Ȼ���������ֱ��dfs��bfs����

const int MAXN = 1e5+5;
vector<int> g[MAXN],ansbfs,ansdfs;          //g��ͼ
int n,m,vis[MAXN];                          //vis�жϵ��Ƿ������
void dfs(int pos,int num) {                 //posΪ��ǰλ�ã�numΪ�Ѿ�����������
    if(num==n+1) return;                    //˵��n�����ҵ���
    for(int i = 0;i < g[pos].size();i++) {  //��������ָ���
        int now = g[pos][i];
        if(vis[now]) continue;              //�����ѱ����ĵ�
        vis[now] = 1;                       //��ǵ�ǰ��
        ansdfs.push_back(now);              //��¼dfs��
        dfs(now,num+1);                     //����dfs
    }
}
void bfs() {
    memset(vis,0,sizeof(vis));              //��ʼ��Ϊ0
    queue<int> q;
    q.push(1);                              //���Ϊ1
    vis[1] = 1;                             //������
    ansbfs.push_back(1);                    //��¼���
    while(!q.empty()) {
        int dot = q.front();                //ȡ����
        q.pop();
        for(int i = 0;i < g[dot].size();i++) {//��������ָ���
            int now = g[dot][i];
            if(vis[now]) continue;          //�����ѱ����ĵ�
            vis[now] = 1;                   //��ǵ�ǰ��
            ansbfs.push_back(now);
            q.push(now);                    //�������
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);                  //��ͼ
    }
    for(int i = 1;i <= n;i++) sort(g[i].begin(),g[i].end());//ָ�������
    ansdfs.push_back(1);                    //dfs���
    vis[1] = 1;
    dfs(1,1);
    bfs();
    for(auto v:ansdfs) cout<<v<<" ";        //�����Ӧ���
    cout<<"\n";
    for(auto v:ansbfs) cout<<v<<" ";
    return 0;
}
