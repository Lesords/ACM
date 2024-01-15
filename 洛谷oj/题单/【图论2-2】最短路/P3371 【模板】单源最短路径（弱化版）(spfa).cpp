#include<iostream>//ac
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e5+5;
struct edge{
    ll dot,val;//dotΪָ��㣬valΪ��ֵ
};
ll n,m,s,dis[MAXN];//dis�������
bool vis[MAXN];//�ж��Ƿ��ڶ����У�trueΪ����ӣ�
vector<edge> g[MAXN];//��ͼ
void spfa(int dot) {
    for(int i = 1;i <= n;++i) dis[i] = INF,vis[i] = true;//��ʼ��
    queue<int> q;
    q.push(dot);//��ʼ�����Դ��
    dis[dot] = 0;//Դ��ľ���Ϊ0
    vis[dot] = false;//�������
    while(!q.empty()) {//�����в�Ϊ��
        int tmp = q.front();q.pop();
        vis[tmp] = true;//����֮���޸�vis
        for(int i = 0;i < g[tmp].size();++i) {
            edge now = g[tmp][i];//ָ��㼰��ֵ
            if(dis[now.dot]>dis[tmp]+now.val) {//���ɳ�
                dis[now.dot] = dis[tmp] + now.val;//ȡСֵ
                if(vis[now.dot]) {//�ж��Ƿ�������
                    q.push(now.dot);
                    vis[now.dot] = false;//����vis
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(edge{v,w});//��ͼ
    }
    spfa(s);//��s�㿪ʼspfa
    for(int i = 1;i <= n;i++) {
        if(i!=1) cout<<" ";
        if(dis[i]==INF) cout<<(1<<31)-1;//���ɵ��������
        else cout<<dis[i];
    }
    cout<<"\n";
    return 0;
}
