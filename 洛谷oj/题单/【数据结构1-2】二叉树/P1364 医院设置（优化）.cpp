#include<iostream>//ac
#include<vector>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺��1Ϊ���������������ɽڵ������㣬����ÿ�����Ե�ǰ��Ϊ����������С
//�ڼ���������С��ʱ�����һ����� �Ը�ΪҽԺ����Ҫ�ߵ�·�̺�
//Ȼ���ÿ������·���ͣ����ȡ��Сֵ
//·���͵�ת�Ʒ��̣�f[now] = f[dot] + (siz[1]-siz[now]) - siz[now]
//����f�����Ǵ洢·�̺ͣ�sizΪ������С
//��Ϊ����������dot�ľ���ֳ����֣�now�������ڵ㣬����now�������ڵ�
//����now�������ڵ���˵��������һ��
//���ڲ���now�������ڵ���˵��������һ����dot->now��
//now�������ڵ���Ϊ��siz[now]������now�������ڵ���Ϊ��siz[1]-siz[now]
//���У�siz[1]��Ϊ����

const int MAXN = 105;
vector<int> g[MAXN];//��ͼ
int num[MAXN],f[MAXN],siz[MAXN],ans = INF;
//num��¼���еľ�������f��¼�Ե�ǰ��Ϊ�����ܾ��룬siz��¼�Ե�ǰ��Ϊ����������С
//dfs����������С����������1Ϊ�����ܾ���(1Ϊ��㣬��������ת��)
void dfs(int dot,int fa,int dep) {//dotΪ��ǰ�ڵ㣬faΪ���ڵ㣬depΪ��ǰ������
    siz[dot] = num[dot];//��ʼ��Ϊ��ǰ��ľ�����
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        if(now==fa) continue;//�������ڵ�
        dfs(now, dot, dep+1);
        siz[dot] += siz[now];//�ۼ�������С
    }
    f[1] += num[dot]*dep;//�ۼ�dot����1��·����
}
//dp����ÿ�����е�·�̺�
void dp(int dot,int fa) {//dotΪ��ǰ�ڵ㣬faΪ���ڵ�
    for(int i = 0;i < g[dot].size();i++) {
        int now = g[dot][i];
        if(now==fa) continue;//�������ڵ�
        f[now] = f[dot] + (siz[1]-siz[now]) - siz[now];//ת��
        dp(now, dot);//�������¼��㣨����ÿ���㣩
    }
    ans = min(ans, f[dot]);//ȡ��Сֵ
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int u,v;
        cin>>num[i]>>u>>v;
        if(u) {//��������ӣ�����
            g[i].push_back(u);
            g[u].push_back(i);
        }
        if(v) {//�����Ҷ��ӣ�����
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }
    dfs(1,0,0);//����ÿ����������С
    dp(1,0);//����ÿ�����·�̺ͣ���ȡ��Сֵ
    cout<<ans;
    return 0;
}
