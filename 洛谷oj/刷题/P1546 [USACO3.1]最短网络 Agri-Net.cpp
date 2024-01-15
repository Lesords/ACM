#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;

//��⣺����vector��ߣ�Ȼ����Kruskal����

const int MAXN = 105;
struct node{
    int u,v,w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;               //���ȱ�ȨС��
    }
};
vector<node> g;                         //��ͼ
int dis[MAXN];                          //������
int getf(int pos) {                     //��ѯ����
    return dis[pos]==pos?pos:dis[pos] = getf(dis[pos]);
}
int main() {
    int n,tmp;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin>>tmp;
            if(i==j) continue;          //��������
            g.push_back({i,j,tmp});
        }
        dis[i] = i;                     //��ʼ������Ϊ����
    }
    sort(g.begin(),g.end());            //����Ȩ����
    int ans = 0;
    for(int i = 0;i < g.size();i++) {   //�������б�
        node tmp = g[i];
        if(getf(tmp.u)!=getf(tmp.v)) {  //����δ���������У���ѡ��ǰ��
            ans += tmp.w;
            dis[getf(tmp.u)] = getf(tmp.v);
        }
    }
    cout<<ans;
    return 0;
}
