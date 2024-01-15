#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺����floyd�㷨˼�����
//������Ҫ���ո����Ĳ�ѯ˳�������������ׯ�����·
//���Ҳ�ѯ��ʱ��˳��Ҳ���ϸ������
//���Կ��԰���ʱ��˳�������¶�Ӧ�����·���ɳڲ�����
//������ǰ��ѯ������ʱ��ǰ�����д�ׯ������
//��Ϊ��ׯ���ؽ�ʱ��Ҳ�� ���� ��

const int MAXN = 205;
int a[MAXN],dis[MAXN][MAXN],n;//a�����ؽ�ʱ�䣬dis��������ľ���
void update(int pos) {//�������п�����posλ����ת��·��
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            //����û�бߵ����
            if(dis[i][pos]==INF||dis[pos][j]==INF) continue;
            dis[i][j] = min(dis[i][j], dis[i][pos]+dis[pos][j]);
        }
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int m,q,now = 1;//nowΪ��ǰ�����Ĵ�ׯ���
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {//��ʼ��
        for(int j = 1;j <= n;j++) {
            if(i==j) dis[i][j] = 0;//��������������ΪINF
            else dis[i][j] = INF;
        }
    }
    for(int i = 1;i <= n;i++) {
        cin>>a[i];//ʱ��Ϊ�����ģ�����
    }
    for(int i = 1;i <= m;i++) {
        int x,y,t;
        cin>>x>>y>>t;
        x++,y++;//������Ŀ�еı�Ŵ�0��ʼ�����Զ���Ҫ+1������
        dis[x][y] = dis[y][x] = t;//�����
    }
    cin>>q;
    for(int i = 1;i <= q;i++) {
        int x,y,t;
        cin>>x>>y>>t;
        x++,y++;//������Ŀ�еı�Ŵ�0��ʼ�����Զ���Ҫ+1������
        while(now<=n&&a[now]<=t) {//nowΪ��ǰ��ׯ���
            //��ǰ��ѯ��ʱ����ڵ�ǰ��ׯ���ؽ���������
            update(now);
            now++;//�Ƶ���һ����ׯ
        }
        if(a[x]>t||a[y]>t) cout<<"-1\n";//����һ��ׯδ����
        else {
            if(dis[x][y]==INF) cout<<"-1\n";//����ΪINF˵���м��д�ׯδ����
            else cout<<dis[x][y]<<"\n";
        }
    }
    return 0;
}
