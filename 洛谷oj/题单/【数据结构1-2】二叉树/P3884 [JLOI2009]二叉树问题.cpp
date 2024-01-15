#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺����bfs�������Ŀ�Ⱥ����
//Ȼ����������dfs���������lca
//��һ������dfs����Ǿ����Ľڵ㣬�ڶ�������dfs�յ��һ�������б�ǵļ�Ϊlca

const int MAXN = 105;
struct node{
    int dot,dep;//dotΪ�ڵ��ţ�depΪ�ڵ����
};
vector<int> g[MAXN];//��ͼ
int n,s,t,num[MAXN],numd[MAXN],vis[MAXN],ans,cnt;//ansΪlca��cnt�������ʵı��
//num��¼��Ӧ��ȵĽڵ�����numdΪ��Ӧ�ڵ����ȣ�vis��¼��Ӧ�ڵ�ķ��ʱ�ţ�lca
void cal(int rt,int &wid,int &dep) {//�����Ⱥ����
    queue<node> q;
    q.push({rt, 1});//���ڵ�
    wid = dep = 1;//��ʼ����Ⱥ���ȶ�Ϊ1
    numd[rt] = 1;//rt��ȵ�����Ϊ1
    while(!q.empty()) {
        node tmp = q.front();
        q.pop();
        for(int i = 0;i < g[tmp.dot].size();i++) {//��������ָ���
            int now = g[tmp.dot][i];
            if(numd[now]) continue;//�����Ѽ�����ȵĵ㣨�ѱ���
            num[tmp.dep+1]++;//��Ӧ��ȵ�����++
            numd[now] = tmp.dep+1;//��¼��ǰ�ڵ�����
            q.push({now,tmp.dep+1});//���
            dep = max(dep, tmp.dep+1);//����������
        }
    }
    for(int i = 2;i <= dep;i++) {//����������ȣ��������
        wid = max(wid, num[i]);
    }
}
void dfs(int dot,int flag) {//flagΪ0��ʾ�������dfs��flagΪ1��ʾ�յ�����dfs��lca
    if(flag&&vis[dot]) {//���е�ǰ�㼴Ϊlca�������Ҫô������Ƚ���λ�ã�������
        ans = dot;return;
    }
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        //������ȴ��ڵ�ǰ��Ľڵ㣬����Ҫ������
        if(numd[now]>numd[dot]) continue;
        if(flag&&vis[now]) {//����lcaʱ����һ����ǵĽڵ㼴Ϊlca
            ans = now;return;
        }
        if(!flag) vis[now] = ++cnt;//Ԥ����ʱ����ǽڵ�ż���
        if(flag&&ans) return;//lca�����ֱ꣬�ӷ���
        dfs(now,flag);//��������
    }
}
void solve(int s,int t) {//����s��t��lca
    vis[s] = ++cnt;//����s���
    dfs(s,0);//Ԥ����
    dfs(t,1);//t����Ѱ��lca
}
int main() {
    cin>>n;
    for(int i = 1;i <= n-1;i++) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);//��˫���
        g[v].push_back(u);
    }
    cin>>s>>t;
    int dep = 0,wid = 0;
    cal(1,wid,dep);//�����Ⱥ����
    solve(s,t);//����lca
    //������������������һ��
    cout<<dep<<"\n"<<wid<<"\n"<<((numd[s]-numd[ans])*2+numd[t]-numd[ans]);
    return 0;
}
