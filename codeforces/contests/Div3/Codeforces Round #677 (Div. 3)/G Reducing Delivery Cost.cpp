#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣻����n��dijkstra�����ÿ��������֮�����С����
//Ȼ��������бߣ����㵱ǰ��Ϊ0�����������·�ߵ���С�����

typedef pair<int,int> pii;
const int MAXN = 1e3+5;
struct node{
    int v,w;
    friend bool operator < (node a,node b) {
        return a.w > b.w;//����ȨֵС��
    }
};
vector<node> g[MAXN];
vector<pii> route,edge;//�洢·�ߺͱ�
int f[MAXN][MAXN],dis[MAXN],vis[MAXN];
int n,m,k;
void dijkstra(int s) {//����sΪ�������·��
    memset(dis,0x3f,sizeof(dis));//��ʼ��Ϊ���ֵ
    memset(vis,0,sizeof(vis));//�������
    dis[s] = 0;//��Ҫ��ǰ��ǣ�����
    priority_queue<node> q;
    q.push({s,0});//���
    while(!q.empty()) {
        node tmp = q.top();q.pop();
        if(vis[tmp.v]) continue;//�������жϵ�
        vis[tmp.v] = 1;//���򣬱�ǵ�ǰ��
        for(int i = 0;i < g[tmp.v].size();i++) {//�������п��Ե���ĵ�
            node now = g[tmp.v][i];
            if(dis[now.v]>dis[tmp.v]+now.w) {
                dis[now.v] = dis[tmp.v]+now.w;
                q.push({now.v,dis[now.v]});
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        f[s][i] = dis[i];
    }
}
int main() {
    cin>>n>>m>>k;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        edge.push_back({u,v});//���
        g[u].push_back({v,w});//��ͼ�������
        g[v].push_back({u,w});
    }
    for(int i = 1;i <= n;i++) {//��n��dijkstra
        dijkstra(i);
    }
    for(int i = 1;i <= k;i++) {//��·��
        int x,y;
        cin>>x>>y;
        route.push_back({x,y});
    }
    ll ans = INF;
    for(int i = 0;i < edge.size();i++) {
        pii ee = edge[i];
        ll num = 0;
        for(int j = 0;j < route.size();j++) {
            pii rr = route[j];
            //����ee�����ߣ���ȡrr·�ߵĽ�Сֵ
            //Ҫôrr.fi -> ee.fi  =>  ee.se -> rr.se
            //Ҫôrr.se -> ee.fi  =>  ee.se -> rr.fi
            num += min(f[rr.fi][rr.se],min(f[rr.fi][ee.fi]+f[rr.se][ee.se],f[rr.fi][ee.se]+f[rr.se][ee.fi]));
        }
        ans = min(ans,num);//ȡ��Сֵ
    }
    cout<<ans;
	return 0;
}
