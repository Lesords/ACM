#include<iostream>//ac
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

//��⣺ֱ��bfs�����1����������·����¼·����
//����ٴα������õص㣬�Ҿ���һ�£������·����
//ע�⣺��Ŀ�и�����������ߣ�����ߣ�����ߣ�����

const int MAXN = 1e6+5;
const int MOD = 100003;
vector<int> g[MAXN];
int dis[MAXN],num[MAXN],vis[MAXN];//dis����Ӷ���1���õ�ľ���
//numΪ���ﵱǰ���·������vis��¼��ǰ���Ƿ񱻷��ʹ�
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);//����ߣ�����
        g[y].push_back(x);
    }
    queue<int> q;
    q.push(1);//���Ϊ1
    num[1] = 1;//���·����Ϊ1
    vis[1] = 1;//���1
    while(!q.empty()) {
        int pos = q.front();
        q.pop();
        for(int i = 0;i < g[pos].size();i++) {//��������ָ���
            int now = g[pos][i];
            if(!vis[now]) {//���Ϊ��һ�α����õ�
                num[now] = num[pos]%MOD;
                dis[now] = dis[pos]+1;//����Ϊ��һ��+1
                vis[now] = 1;//���
                q.push(now);//���
            }
            else if(dis[now]==dis[pos]+1) {
                num[now] = (num[now]+num[pos])%MOD;//�ٴα������ۼ�·����
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        cout<<num[i]<<"\n";
    }
    return 0;
}
