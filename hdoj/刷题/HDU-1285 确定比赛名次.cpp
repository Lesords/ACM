#include<iostream>//ac
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN= 505;
int n,m,in[MAXN],ans[MAXN];
vector<int> edge[MAXN];
int main () {
    while(cin>>n>>m) {//�������룡����
        int p1,p2;
        memset(in,0,sizeof(in));//��ʼ�������Ϣ
        for(int i = 1;i <= m;i++) {
            cin>>p1>>p2;
            edge[p1].push_back(p2);//��� ��p1->p2��
            in[p2]++;
        }
        priority_queue<int,vector<int>,greater<int> > q;//���С����ǰ
        for(int i = 1;i <= n;i++) {//�����г�ʼ���Ϊ0�ķ��������ȥ
            if(in[i]==0) q.push(i);
        }
        int cnt = 0,tmp;
        while(!q.empty()) {
            tmp = q.top();q.pop();
            ans[++cnt] = tmp;//q������ÿ������Ҫ����
            for(int i = 0;i < edge[tmp].size();i++) {//�жϵ�ǰ��ָ��λ��
                int dot = edge[tmp][i];
                in[dot]--;//ָ��λ�õ����е����--
                if(in[dot]==0) q.push(dot);//���Ϊ0�ķ���q������ȥ
            }
        }
        for(int i = 1;i <= cnt;i++) {//��֤�н⣬���Դ�ʱcnt=n
            if(i!=1) cout<<' ';
            cout<<ans[i];
        }
        cout<<endl;
        for(int i = 1;i <= n;i++) edge[i].clear();//��ձ���Ϣ
    }
    return 0;
}
