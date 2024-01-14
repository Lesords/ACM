#include<iostream>//ac �������㷨
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 505;
int k,m,n;
int vis[MAXN],match[MAXN];//vis��¼�Ƿ��жϹ���match��¼ƥ��Ķ�����
vector<int> g[MAXN];//��ͼ
int dfs(int u) {//������·
    for(int i = 0;i < g[u].size();i++) {
        int now = g[u][i];
        if(vis[now]) continue;//�������жϵĵ�
        vis[now] = 1;
        //δƥ�� �� ƥ��Ķ������µĶ���
        if(match[now]==0||dfs(match[now])) {
            match[now] = u;//����ƥ��Ķ���
            return 1;
        }
    }
    return 0;
}
int hungarian() {//����ƥ�������
    int ans = 0;
    for(int i = 1;i <= m;i++) {
        for(int j = 1;j <= n;j++) vis[j] = 0;//�������
        if(dfs(i)) ans++;
    }
    return ans;
}
int main() {
    while(cin>>k&&k) {
        memset(match,0,sizeof(match));//��ʼ��
        cin>>m>>n;
        for(int i = 1;i <= m;i++) g[i].clear();//��ʼ��
        for(int i = 1;i <= k;i++) {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);//��ͼ
        }
        //��װ��ֱ�ӵ���
        cout<<hungarian()<<"\n";
    }
    return 0;
}
