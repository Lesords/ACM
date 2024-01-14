#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<vector>
#include<utility>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺���鼯+��������
//���ò��鼯��������ȵĵ�����һ���㣬Ȼ�����ʣ����ٵ㣨res��
//������ʣ��ĵ�������������жϵ�ʱ�����ж�ԭ��������ʣ��ĵ�����res��

const int MAXN = 1e4+5;
int n,m,fa[MAXN],in[MAXN];//fa��¼���鼯�����е����ȣ�inΪ���
vector<int> g[MAXN];//��ߣ��ߵ�ָ��͵ģ�
vector<pii> a;//��¼�ߵ�����
set<int> st;//���˹��̼�¼�Ѿ����ĵ�
int getf(int x) {//·��ѹ��
    return x==fa[x]?x:fa[x] = getf(fa[x]);
}
int main() {
    while(scanf("%d%d",&n,&m)==2) {
        memset(in,0,sizeof(in));
        st.clear(), a.clear();
        for(int i = 0;i < n;i++) g[i].clear(),fa[i] = i;//��ʼ��
        for(int i = 1;i <= m;i++) {
            int x,y;
            char op;
            scanf("%d%*c%c%*c%d",&x,&op,&y);
            x = getf(x),y = getf(y);
            if(op=='=') {
                if(x!=y) fa[y] = x;//����ϲ�
            }
            else if(op=='<') a.push_back(make_pair(y,x));
            else a.push_back(make_pair(x,y));//��¼�ߣ���->�ͣ�
        }
        for(int i = 0;i < a.size();i++) {
            int x = getf(a[i].fi);
            int y = getf(a[i].se);//��ͼ�����ȵ�
            g[x].push_back(y);//����Ҫ�����ظ��ߣ������ߵ�ʱ���һ����ɾ����
            in[y]++;//���++
        }
        priority_queue<int> q;
        int flag = 0,num = 0,res = 0;
        for(int i = 0;i < n;i++) res += fa[i]==i;//resΪʣ��ĵ���
        for(int i = 0;i < n;i++) {
            if(getf(i)!=i) continue;//�������Ǵ���ĵ�
            if(in[getf(i)]==0) q.push(getf(i));//ָ���һ��
        }//push���Բ���������ֵ���������˵�ʱ����޸Ķ�Ӧ��ָ������
        while(!q.empty()) {
            int tmp = q.top();q.pop();
            if(st.count(tmp)) continue;//�����ѱ�ǵ�
            else st.insert(tmp);//����������
            if(!q.empty()) {//��ѡ��㲻Ϊ1������Ϊ��Ϣ����ȫ
                flag = 1;
            }
            num++;//�������е�����++
            for(int i = 0;i < g[tmp].size();i++) {//�������бߣ��ɴ����ظ��ߣ�
                int dot = g[tmp][i];
                --in[dot];//��Ӧ������--
                if(in[dot]==0) q.push(dot);//�����Ϊ0���������
            }
        }//��ͻʵ���Ͼ����л�
        if(num<res) cout<<"CONFLICT\n";//������ͻ����Ҫ����ˣ�����
        else {//ֻ������ͻ�����ȼ��ߣ�����
            if(flag) cout<<"UNCERTAIN\n";
            else cout<<"OK\n";
        }
    }
    return 0;
}
