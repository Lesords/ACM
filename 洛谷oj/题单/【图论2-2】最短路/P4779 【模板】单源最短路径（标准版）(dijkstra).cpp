#include<iostream>//ac
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
const int MAXN = 1e5+5;
struct edge{
    ll dot,val;
    friend bool operator < (edge a,edge b) {
        return a.val > b.val;//��С
    }
};
ll n,m,s,vis[MAXN],dis[MAXN];//vis�жϵ�ǰ�Ƿ��Ѿ�ȷ����disΪ����
vector<edge> g[MAXN];//��ͼ
void dijkstra(int dot) {
    for(int i = 1;i <= n;i++) dis[i] = INF;//��ʼ��
    dis[dot] = 0;//Դ��Ϊ0
    priority_queue<edge> q;//���ȶ���
    q.push(edge{dot,0});//Դ�������
    while(!q.empty()) {
        edge tmp = q.top();q.pop();
        if(vis[tmp.dot]) continue;//������ȷ����
        else vis[tmp.dot] = 1;//������
        for(int i = 0;i < g[tmp.dot].size();i++) {//�������пɵ����
            edge now = g[tmp.dot][i];
            if(dis[now.dot]>dis[tmp.dot]+now.val) {//�ɳڲ���
                dis[now.dot] = dis[tmp.dot]+now.val;
                //δ���ʣ���������
                if(!vis[now.dot]) q.push(edge{now.dot,dis[now.dot]});
            }
        }
    }
}
int main() {
    cin>>n>>m>>s;
    for(int i = 1;i <= m;i++) {
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(edge{v,w});//��ͼ
    }
    dijkstra(s);//��dijkstra
    for(int i = 1;i <= n;i++) {
        if(i!=1) cout<<" ";
        cout<<dis[i];
    }
    return 0;
}
