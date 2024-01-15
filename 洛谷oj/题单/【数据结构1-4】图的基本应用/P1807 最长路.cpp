#include<iostream>//ac
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

//��⣺���������1��ʼ����ά������������Զ����
//��Ҫע�⣺�еĵ�1�޷�����������ҲΪ0���������ȴ����Ӧ��ָ�������--

const int MAXN = 1510;
struct node{
    int dot,val;//dot�洢ָ��㣬val�洢��Ȩ
};
vector<node> g[MAXN];//��ͼ
int in[MAXN],to[MAXN];//in����ȣ�to���1����ĳ�����Զ����
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {//m����
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(node{v,w});//�洢��
        in[v]++;//���
    }
    for(int i = 2;i <= n;i++) {//�������������������Ϊ0�����
        if(in[i]) continue;
        for(int j = 0;j < g[i].size();j++) in[g[i][j].dot]--;//ָ������--
    }
    queue<int> q;
    q.push(1);//��1��ʼ
    while(!q.empty()) {//��������
        int tmp = q.front();q.pop();
        for(int i = 0;i < g[tmp].size();i++) {//��������ָ���
            node tt = g[tmp][i];
            to[tt.dot] = max(to[tt.dot],to[tmp]+tt.val);//������Զ����
            if(--in[tt.dot]==0) {//�����Ϊ0�������
                q.push(tt.dot);
            }
        }
    }
    if(to[n]==0) cout<<"-1\n";//Ϊ0��ʾ����ͨ
    else cout<<to[n]<<endl;
    return 0;
}
