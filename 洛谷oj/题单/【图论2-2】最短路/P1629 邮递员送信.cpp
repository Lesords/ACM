#include<iostream>//ac
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;

//��⣺����㵽������ľ���ͣ�Ϊ��Դ���·�����⣬ֱ��dijkstra����
//�������ڱ�Ϊ����ģ����Է��ص�·���Ƕ�Դ���յ�����·������
//���Կ��Է��򽨱ߣ���ô�Ϳ��Խ���Դ���յ�����ת��Ϊ��Դ���·��������
//���ڼ��д�������ǿ���ֱ�ӽ���ı�Ŷ�+n����������ԭͼ��

const int MAXN = 2e3+10;
struct node{
    int v,w;
    friend bool operator < (node a,node b) {
        return a.w > b.w;//���ȱ�ȨС��
    }
};
int n,m;
int dis[MAXN],vis[MAXN];//dis��¼���룬vis�жϵ�ǰ���Ƿ��ɳڹ�
vector<node> g[MAXN];//�����
void dijkstra(int s,int pls) {//sΪ��㣬plsΪ���ӵľ��루���򽨱�+n
    for(int i = 1;i <= n;i++) dis[i+pls] = INF;//��¼���붼��Ҫ+pls
    priority_queue<node> q;
    q.push({s+pls,0});//���Ϊs+pls������Ϊ0
    dis[s+pls] = 0;//s+pls����Ϊ0
    while(!q.empty()) {
        node pos = q.top();
        q.pop();
        if(vis[pos.v]) continue;//�������ɳڵ�
        vis[pos.v] = 1;//������
        for(int i = 0;i < g[pos.v].size();i++) {//�������п���ָ��ı�
            node now = g[pos.v][i];
            if(dis[now.v]>dis[pos.v]+now.w) {//�����ɳ�
                dis[now.v] = dis[pos.v] + now.w;//����Ȩֵ
                q.push({now.v,dis[now.v]});//ָ������
            }
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});//����
        g[v+n].push_back({u+n,w});//���򽨱ߣ����+n
    }
    ll ans = 0;
    dijkstra(1,0);//����
    dijkstra(1,n);//�����
    for(int i = 1;i <= n*2;i++) ans += dis[i];//ǰnΪ���򣬺�nΪ����
    cout<<ans;
    return 0;
}
