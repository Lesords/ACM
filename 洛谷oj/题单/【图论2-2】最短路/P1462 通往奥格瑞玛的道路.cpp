#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺���ִ�+dijkstra
//�����г��еĹ�·�Ѵ�С��������Ȼ��������������Ϊ���ֵķ�Χ
//dijkstra�����㵽�����������ʧ��Ѫ����ע���жϹ�·���Ƿ���������

const int MAXN = 1e4+5;
struct node{
    int v,w;
    friend bool operator < (node a,node b) {
        return a.w > b.w;//����ȨֵС��
    }
};
int n,m,b;
int f[MAXN],c[MAXN],dis[MAXN],vis[MAXN];//vis��¼��ǰ�����Ƿ��жϹ�
//fΪ��·��ԭ���飬cΪ��·���������飬dis�洢����õ���ʧ��Ѫ��
vector<node> g[MAXN];//��ͼ
bool judge(int tval) {
    for(int i = 1;i <= n;i++) dis[i] = INF,vis[i] = 0;//��ʼ��
    priority_queue<node> q;
    q.push({1,0});
    dis[1] = 0;//�����ʧΪ0
    while(!q.empty()) {
        node tmp = q.top();
        q.pop();
        if(vis[tmp.v]) continue;//�����ѱ�ǵ�
        vis[tmp.v] = 1;//������
        for(int i = 0;i < g[tmp.v].size();i++) {//�������п�ָ���
            node now = g[tmp.v][i];
            if(f[now.v]>tval) continue;//������·�Ѵ���tval�ĳ��У�����
            if(dis[now.v]>dis[tmp.v]+now.w) {//�����ɳ�
                dis[now.v] = min(dis[now.v], dis[tmp.v]+now.w);
                q.push({now.v,dis[now.v]});//���²����
            }
        }
    }
    if(dis[n]>b) return false;//�������n���е���ʧѪ������b������������
    return true;
}
int main() {
    cin>>n>>m>>b;
    for(int i = 1;i <= n;i++) cin>>f[i],c[i] = f[i];
    for(int i = 1;i <= m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back({b,c});//�����
        g[b].push_back({a,c});
    }
    if(!judge(INF)) {//�����ԭ�����¾��޷�����n�㣬��ֱ�����AFK
        cout<<"AFK\n";//����ʧ��Ѫ������
        return 0;
    }
    sort(c+1,c+n+1);//��·�Ѵ�С��������
    int l = 1,r = n,ans = 0;//�Թ�·��Ϊ���ַ�Χ
    while(l<=r) {
        int mid = (l+r)>>1;
        if(judge(c[mid])) {//�ж�c[mid]�Ĺ�·���Ƿ���������
            ans = c[mid];//��������½��
            r = mid-1;
        }
        else l = mid+1;
    }
    cout<<ans;
    return 0;
}
