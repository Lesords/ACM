#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺����ֻ��k���ߵ����������
//��ѡ��ߵ�ʱ���¼�ߵ���������ѡ��k����ֱ�ӽ���

const int MAXN = 1e5+5;
struct node{
    int x,y,z;
    friend bool operator < (node a,node b) {
        return a.z > b.z;//����ѡ���Ȩ���
    }
}a[MAXN];
int dis[MAXN];//��¼����
int getf(int p) {//Ѱ��p������
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++) dis[i] = i;//��ʼ��Ϊ����
    for(int i = 1;i <= m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[i] = {x,y,z};//���
    }
    sort(a+1,a+m+1);//���򣨴Ӵ�С
    int ans = 0;
    for(int i = 1;i <= m;i++) {//mΪ��Χ��������k����Ϊ��Щ�߲���������������
        node tmp = a[i];
        if(getf(tmp.x)!=getf(tmp.y)) {//����δ���������У�������
            ans += tmp.z;//��ӱ�Ȩֵ
            dis[getf(tmp.x)] = dis[getf(tmp.y)];//����ϲ�
            k--;//��ѡ��ı���--
        }
        if(k==0) break;//Ϊ0����ʾû��ѡ�ˣ�ֱ�ӽ���
    }
    cout<<ans;
    return 0;
}
