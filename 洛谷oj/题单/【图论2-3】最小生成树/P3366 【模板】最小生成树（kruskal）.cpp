#include<iostream>//ac
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 2e5+5;
struct node{
    int x,y,z;
    friend bool operator < (node a,node b) {
        return a.z < b.z;                       //���ȱ�ȨС��
    }
}a[MAXN];
int dis[MAXN];                                  //��¼���Ƚڵ�
int getf(int p) {                               //�����ȣ�·��ѹ��
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) dis[i] = i;       //��ʼ������Ϊ����
    for(int i = 1;i <= m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[i] = {x,y,z};                         //���
    }
    sort(a+1,a+1+m);                            //����Ȩ��С��������
    int ans = 0, cnt = 1;
    for(int i = 1;i <= m;i++) {                 //��m��������ѡ��
        node tmp = a[i];
        if(getf(tmp.x)!=getf(tmp.y)) {          //�������㻹δ����
            ans += tmp.z;                       //��ӱ�Ȩֵ
            cnt++;
            dis[getf(tmp.x)] = dis[getf(tmp.y)];//���
        }
    }
    if(cnt!=n) cout<<"orz";
    else cout<<ans;
    return 0;
}
