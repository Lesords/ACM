#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺���������s��t��·�����ı�Ȩֵ��������С��
//��ô��������Kruskal���������������ǰ������֮��s��t��ͨ
//��ô��ǰ�ߵı�Ȩ��Ϊ�������ΪKruskal�ı�Ȩ�Ǵ�С����ѡ��

const int MAXN = 2e4+5;
struct node{
    int u,v,w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;//���ȱ�ȨС��
    }
}a[MAXN];
int dis[MAXN];//��¼����
int n,m,s,t;
void init() {//��ʼ������Ϊ����
    for(int i = 1;i <= n;i++) dis[i] = i;
}
int getf(int p) {//��ȡp�����ȣ�·��ѹ��
    return dis[p]==p?p:getf(dis[p]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m>>s>>t;
    for(int i = 1;i <= m;i++) {
        int u,v,w;
        cin>>u>>v>>w;
        a[i] = {u,v,w};//���
    }
    sort(a+1,a+m+1);//����
    int ans = 0;
    init();
    for(int i = 1;i <= m;i++) {
        node tmp = a[i];
        if(getf(tmp.u)!=getf(tmp.v)) {//�����������У�������
            dis[getf(tmp.u)] = dis[getf(tmp.v)];
        }
        if(getf(s)==getf(t)) {//s��t��ͨ����ǰ��ȨΪ���
            ans = tmp.w;break;
        }
    }
    cout<<ans;
    return 0;
}
