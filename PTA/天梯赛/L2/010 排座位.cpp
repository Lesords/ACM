#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e2+5;

//��⣺���ò��鼯�������ѵļ�ӹ�ϵ���ö�ά���鱣�����ѵ�ֱ�ӹ�ϵ������
//��Ϊ����ֻ��Ҫ�ж�ֱ�ӹ�ϵ�������ݷ�Χ��С���ʿ�ֱ���ö�ά����

int a[MAXN][MAXN],fa[MAXN];//a���鱣������֮���ֱ�ӹ�ϵ��fa�������ѵĹ�ϵ������ӹ�ϵ��
int getF(int x) {//·��ѹ��
    return fa[x]==x?x:fa[x] = getF(fa[x]);
}
void Merge(int x,int y) {//�ϲ�
    x = getF(x),y = getF(y);
    if(x!=y) fa[y] = x;//����ϲ�
}
int main() {
    int n,m,k;
    cin>>n>>m>>k;
    for(int i = 1;i <= n;i++) fa[i] = i;//��ʼ��
    for(int i = 1;i <= m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[x][y] = a[y][x] = z;//����ֻ��Ҫ����ֱ�ӵ��ˣ�����
        if(z==1) {//���Ѳ���Ҫ���鼯
            Merge(x,y);
        }
    }
    for(int i = 1;i <= k;i++) {
        int x,y;
        cin>>x>>y;
        if(a[x][y]==1) cout<<"No problem\n";//ֱ������
        else if(a[x][y]==-1) {//ֱ�ӵ���
            if(getF(x)==getF(y)) cout<<"OK but...\n";//�й�ͬ����
            else cout<<"No way\n";
        }
        else cout<<"OK\n";//ʲô��û��
    }
    return 0;
}
