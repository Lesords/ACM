#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 505;
struct node{
    int dot,val;//dotΪָ��㣬valΪ��Ӧ�ߵĳ���
    friend bool operator < (node a,node b) {
        return a.val > b.val;
    }
};
vector<node> g[MAXN];//g��ͼ
int n,m,s,d,num[MAXN],pa[MAXN],cnt[MAXN],sum[MAXN],dis[MAXN],vis[MAXN];
//num�����Ӧ���еĶ���������pa�����Ӧ���е���һ��λ��
//cnt���浽���Ӧ���е�·������sumΪ�����Ӧ���п����еĶ�������
//dis��ʾ�����Ӧλ�õĳ��ȣ�vis���浱ǰ�����Ƿ��ɳڹ�
void dijkstra(int s) {
    for(int i = 0;i < n;i++) dis[i] = INF;//��ʼ��Ϊ���޴�
    dis[s] = 0;//Դ���·��Ϊ0
    cnt[s] = 1;//Դ���·����Ϊ1
    sum[s] = num[s];//Դ��Ķ�������Ϊ���������
    priority_queue<node> q;
    q.push(node{s,0});//Դ�����
    while(!q.empty()) {
        node tmp = q.top();q.pop();
        if(vis[tmp.dot]) continue;//���ɳڵ�����
        else vis[tmp.dot] = 1;//�����ĸ�ֵΪ1
        for(int i = 0;i < g[tmp.dot].size();i++) {
            node now = g[tmp.dot][i];
            if(dis[now.dot]>dis[tmp.dot]+now.val) {//���ɳ�
                dis[now.dot] = dis[tmp.dot]+now.val;//���³���
                pa[now.dot] = tmp.dot;//�޸���һ��λ�ó���
                cnt[now.dot] = cnt[tmp.dot];//·������Ϊ��һ�����е�·����
                sum[now.dot] = num[now.dot] + sum[tmp.dot];//������Ϊ ��ǰ+��һ����������
                if(!vis[now.dot]) q.push(node{now.dot,dis[now.dot]});//δ�ɳڵ����
                //�����ٴα�ǣ���δ�ɳڣ�����
            }
            else if(dis[now.dot]==dis[tmp.dot]+now.val) {//����ȣ���ʾ�ж��·��
                cnt[now.dot] += cnt[tmp.dot];//�ۼ�·����
                if(num[now.dot]+sum[tmp.dot]>sum[now.dot]) {//���������϶࣬�����
                    pa[now.dot] = tmp.dot;//������һ��λ�õĳ���
                    sum[now.dot] = num[now.dot] + sum[tmp.dot];//�޸Ķ�����
                }
            }
        }
    }
}
void out_path(int dot) {//�ݹ����·��
    if(dot==s) {//�������ֱ�����
        cout<<s;
        return ;
    }
    out_path(pa[dot]);//�ȵݹ��������ɴ�ͷ��β�����
    cout<<" "<<dot;
}
int main() {
    cin>>n>>m>>s>>d;
    for(int i = 0;i < n;i++) cin>>num[i];
    for(int i = 1;i <= m;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        g[a].push_back(node{b,c});//��ͼ
        g[b].push_back(node{a,c});
    }
    dijkstra(s);
    cout<<cnt[d]<<" "<<sum[d]<<"\n";
    out_path(d);
    return 0;
}
