#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺������Ҫ��k���޻��ǣ����ֳ�k��
//��ô������������˵����Ϊn��������n-1������ôҪ����k������������Ҫ��ȥ(k-1)����
//������Ҫ�ı�Ϊ��(n-1)-(k-1) = n-k
//Ҳ���Ƕ�ԭͼ����Kruskal��ֻ���� n-k ����С�߼���

const int MAXN = 1e3+5;
const int MAXM = 1e4+5;
struct node{
    int x,y,z;
    friend bool operator < (node a,node b) {
        return a.z < b.z;//���ȱ�ȨС��
    }
}a[MAXM];
int dis[MAXN];//��¼����
int getf(int p) {//Ѱ��p�����ȣ�·��ѹ��
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++) dis[i] = i;//��ʼ������Ϊ��������
    for(int i = 1;i <= m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[i] = {x,y,z};//���
    }
    if(k>n) {//�޻����������ƶ������࣬�޽�
        cout<<"No Answer\n";
        return 0;
    }
    sort(a+1,a+1+m);//����
    int ans = 0,num = 0;//ansΪ�����numΪ��ǰѡ��ı���
    for(int i = 1;i <= m;i++) {
        node tmp = a[i];
        if(getf(tmp.x)!=getf(tmp.y)) {//��δ���������У�������
            ans += tmp.z;//��ӱ�Ȩֵ
            dis[getf(tmp.x)] = dis[getf(tmp.y)];//����ϲ�
            num++;//����++
        }
        if(num==n-k) break;//ֻ��Ҫn-k����
    }
    if(num!=n-k) cout<<"No Answer\n";//����n-k����˵���޽�
    else cout<<ans;
    return 0;
}
