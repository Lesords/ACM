#include<iostream>//ac
#include<vector>
#include<queue>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e3+5;

//��⣺��ͼ����s��spfa������ans���飬��������Сֵ����

struct node{
    int dot,val;//ָ���ͱ�Ȩֵ
};
vector<node> g[MAXN];//��ͼ
int dis[MAXN],ans[MAXN],maxx,minn;
//dis��¼��ǰspfa�Ľ����ans�����ۺ���Сֵ��maxxΪ���ĵ㣬minnΪ�����
bool vis[MAXN];//vis��¼��ǰ���Ƿ��ڶ����У�falseΪ��

void spfa(int dot) {//dotΪԴ��
    for(int i = 1;i <= maxx;i++) {//��ʼ��
        vis[i] = true;//trueΪ���ڶ���
        dis[i] = INF;//��ʼ��ΪINF
    }
    dis[dot] = 0;//Դ��Ϊ��Դ��Ϊ0
    vis[dot] = false;//Դ����
    queue<int> q;
    q.push(dot);//Դ�����
    while(!q.empty()) {
        int tmp = q.front();q.pop();
        vis[tmp] = true;//������Ҫɾ�����
        for(int i = 0;i < g[tmp].size();i++) {//�������пɵ����
            node now = g[tmp][i];
            if(dis[tmp]+now.val<dis[now.dot]) {//·;���
                dis[now.dot] = dis[tmp]+now.val;//�޸ĵ���now.dot��ֵ
                if(vis[now.dot]) {//δ�ڶ����еģ�������
                    q.push(now.dot);
                    vis[now.dot] = false;//������
                }
            }
        }
    }
}

int main() {
    int t,s,d;
    while(cin>>t>>s>>d) {//�������룡����
        maxx = 0,minn = INF;
        for(int i = 1;i <= t;i++) {
            int a,b,time;
            cin>>a>>b>>time;
            maxx = max(maxx,max(a,b));//��¼����
            g[a].push_back(node{b,time});//���
            g[b].push_back(node{a,time});
        }
        for(int i = 1;i <= maxx;i++) ans[i] = INF;//��ʼ��ΪINF
        for(int i = 1;i <= s;i++) {
            int dot;cin>>dot;
            if(dot>maxx) continue;
            spfa(dot);
            for(int j = 1;j <= maxx;j++) ans[j] = min(ans[j],dis[j]);//���½�Сֵ
        }
        for(int i = 1;i <= d;i++) {
            int dot;cin>>dot;
            if(dot>maxx) continue;
            minn = min(minn,ans[dot]);//���ȡ��Сֵ
        }
        for(int i = 1;i <= maxx;i++) g[i].clear();//�������룬�ǵó�ʼ��������
        cout<<minn<<"\n";//�س�������
    }
    return 0;
}
