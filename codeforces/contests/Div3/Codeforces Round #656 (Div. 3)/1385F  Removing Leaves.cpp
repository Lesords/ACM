#include<iostream>//ac
#include<cstdio>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//���⣺��һ���ڵ�ѡ��ɾ��k��Ҷ�ӣ���������ɾ������
//��⣺�������������˼��
//��¼ÿ���ڵ��Ӧ��ָ��㣬�Լ����
//��ô��ɾ�����п���ɾ����Ҷ�ӣ����Ϊ1��������¼��Ӧ���ڵ������Լ����ڵ��Ӧ��ɾ����
//������ڵ��ɾ����Ϊk�ı�������ʾ�ýڵ����������k��Ҷ�ӣ������++
//����պô�ʱ���ڵ�����ҲΪ1����ʾɾ�����нڵ�֮�󣬸��ڵ�Ҳ����ɾ��
//�����ڵ㲻����k��Ҷ�ӣ�������ӣ�ӦΪ������k��Ҷ�ӣ�ɾ�����˶�ӦҶ�ӣ���ɲ����µ�Ҷ��
//ע�⣺��vis�жϸýڵ��Ƿ�ɾ��������ΪkΪ1��ʱ�򣬿��ܻ��ظ�ɾҶ�ӣ�����

const int MAXN = 2e5+5;
int in[MAXN],siz[MAXN],vis[MAXN];//in��¼��ȣ�sizΪ��Ӧ�ڵ��ɾ������vis��¼������Ƿ�ɾ����
vector<int> g[MAXN];//���
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        for(int i = 1;i <= n;i++) {         //��ʼ��
            vis[i] = in[i] = siz[i] = 0;
            g[i].clear();
        }
        for(int i = 1;i < n;i++) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);              //����
            g[v].push_back(u);
            in[u]++,in[v]++;                //��¼��Ӧ���
        }
        queue<int> q;
        int ans = 0;
        for(int i = 1;i <= n;i++) {         //�Ƚ����п���ɾ����Ҷ�����
            if(in[i]==1) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int now = q.front();            //nowΪ����ɾ����Ҷ�ӱ��
            vis[now] = 1;                   //���
            q.pop();
            for(int i = 0;i < g[now].size();i++) {//��������ָ���
                int dot = g[now][i];
                if(vis[dot]) continue;      //������ɾ���Ľڵ�
                in[dot]--;                  //���ڵ�����--
                siz[dot]++;                 //���ڵ��ɾ����++
                if(siz[dot]%k==0) {         //���ɾ��������k�ı���
                    ans++;                  //�������++
                    if(in[dot]==1) {        //��ʱ���������Ϊ1����������
                        q.push(dot);
                    }
                }
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
