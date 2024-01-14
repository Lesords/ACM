#include<iostream>//ac
#include<cstring>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
using namespace std;

//��⣺��ͼ���������򼴿ɣ��ж��Ƿ��л�
//�л���Υ��������Ϸ�

const int MAXN = 105;
int n,m,in[MAXN];//inΪ���
set<int> st;//st�ж��Ƿ���ʹ�
vector<int> g[MAXN];//��ͼ
void init() {//��ʼ��
    memset(in,0,sizeof(in));
    st.clear();
    for(int i = 0;i < n;i++) g[i].clear();
}
bool topo() {//�ж��Ƿ��л�
    int num = 0;
    priority_queue<int> q;//��ʼ��ʱ�������Ϊ0�������
    for(int i = 0;i < n;i++) if(in[i]==0) q.push(i);
    while(!q.empty()) {
        int tmp = q.top();q.pop();
        if(st.count(tmp)) continue;//�����ѱ�ǵ�
        else st.insert(tmp);//����������
        num++;//��¼����
        for(int i = 0;i < g[tmp].size();i++) {//�������б�
            int dot = g[tmp][i];
            in[dot]--;
            if(in[dot]==0) q.push(dot);//���Ϊ0������������
        }
    }
    return num == n;//�ж������Ƿ�Ϊn
}
int main() {
    while(cin>>n>>m&&n+m) {
        init();
        for(int i = 1;i <= m;i++) {
            int x,y;
            cin>>x>>y;
            g[x].push_back(y);//��ͼ
            in[y]++;
        }
        if(topo()) cout<<"YES\n";//�ж��Ƿ��л�����
        else cout<<"NO\n";
    }
    return 0;
}
