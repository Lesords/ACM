#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺������������������м��ɣ�ע���������

const int MAXN = 505;
int n,m,in[MAXN],vis[MAXN];//in��¼��ȣ�vis��ʾ�Ƿ�����
vector<int> g[MAXN],ans;//g��ߣ�ans���
int main() {
    while(cin>>n>>m) {
        for(int i = 1;i <= m;i++) {
            int x,y;
            cin>>x>>y;
            in[y]++;//������Ⱥͱ�
            g[x].push_back(y);
        }
        priority_queue<int,vector<int>,greater<int> > q;//����
        for(int i = 1;i <= n;i++) {
            if(in[i]) continue;
            q.push(i);//���������Ϊ0�ķ������
        }
        while(!q.empty()) {
            int tmp = q.top();q.pop();
            if(vis[tmp]) continue;//�����ѱ�ǵ�
            else vis[tmp] = 1;//����������
            ans.push_back(tmp);//�����
            for(int i = 0;i < g[tmp].size();i++) {
                int dot = g[tmp][i];//����ָ������--
                in[dot]--;
                if(in[dot]==0) q.push(dot);//��Ϊ0�����
            }
        }
        for(int i = 0;i < ans.size();i++) {
            if(i!=0) cout<<" ";
            cout<<ans[i];
        }
        cout<<"\n";
        for(int i = 1;i <= n;i++) vis[i] = in[i] = 0,g[i].clear();
        ans.clear();//���
    }
    return 0;
}
