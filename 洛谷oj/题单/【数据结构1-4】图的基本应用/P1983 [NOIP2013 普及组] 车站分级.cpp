#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺���������ѵ����ڽ��ߵ�˼·
//��ÿ�г�����βͣ���ķ�Χ��ѡ��δͣ������ͣ��������
//��ô�����������֮���ͼ��˵��ֱ�����������򣬼����м��㼴��

const int MAXN = 1e3+2;
struct node{
    int id,pos;                         //idΪ��ǰ���ţ�posΪ����
    friend bool operator < (node a,node b) {
        return a.pos > b.pos;
    }
};
int a[MAXN],in[MAXN],g[MAXN][MAXN];     //in��¼��ȣ�g��ͼ������ȥ��
bool vis[MAXN];                         //��¼��ǰ���Ƿ�ͣ������ͣ����Ϊ1
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {
        int num;
        cin>>num;
        for(int j = 1;j <= num;j++) {
            cin>>a[j];
            vis[a[j]] = 1;                      //��¼ͣ����
        }
        for(int j = a[1];j <= a[num];j++) {     //����β��Χ��Ѱ�ң�����
            if(vis[j]==0) {                     //��ͣ����
                for(int k = 1;k <= num;k++) {
                    //ÿ����ֻ��Ҫ��¼һ����ȣ�����
                    if(!g[j][a[k]]) in[a[k]]++;
                    g[j][a[k]] = 1;             //����
                }
            }
            vis[j] = 0;                         //��գ������ʼ��
        }
    }
    priority_queue<node> q;
    for(int i = 1;i <= n;i++) {                 //�����Ϊ0�ĵ��������У�Ĭ�ϲ���Ϊ1
        if(in[i]==0) q.push({i,1});
    }
    int ans = 0;
    node tmp;
    while(!q.empty()) {
        tmp = q.top();
        q.pop();
        ans = max(ans, tmp.pos);                //����������
        for(int i = 1;i <= n;i++) {
            if(i==tmp.id) continue;             //���������
            if(g[tmp.id][i]) {                  //tmp.id��i���ڱ�
                if(--in[i]==0) {                //�����Ϊ0����������
                    q.push({i,tmp.pos+1});
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
