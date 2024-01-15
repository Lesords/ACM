#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define two(x) (x)*(x)
using namespace std;

//��⣺Kruskal�����Ѿ������ı�Ȩֵ��Ϊ0
//Ȼ��������е�֮��ľ��룬Ȼ�����Kruskal����

const int MAXN = 1e3+5;
const int MAXM = 1e6+1005;
struct node{
    int x,y;
    double z;
    friend bool operator < (node a,node b) {
        return a.z < b.z;//���ȱ�ȨС��
    }
}a[MAXM];
int dis[MAXN];//��¼���Ƚڵ㣨�Ƿ�������
double x[MAXN],y[MAXN];//��¼����
double cal(int i,int j) {//����i��j�ľ���
    return sqrt(two(x[i]-x[j])+two(y[i]-y[j]));
}
int getf(int p) {//����p�����ȣ�·��ѹ��
    return dis[p]==p?p:dis[p]=dis[getf(dis[p])];
}
int main() {
    int n,m,cnt = 0;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>x[i]>>y[i];
        dis[i] = i;//��ʼ������Ϊ����
    }
    for(int i = 1;i <= m;i++) {
        int x,y;
        cin>>x>>y;
        a[++cnt] = {x,y,0};//����ȨΪ0�ı�
    }
    for(int i = 1;i <= n;i++) {//�������е�֮��ľ���
        for(int j = 1;j <= n;j++) {
            if(i==j) continue;//��������
            double val = cal(i,j);//����i��j�ľ���
            a[++cnt] = {i,j,val};//��ӱ�
        }
    }
    sort(a+1,a+cnt+1);//����
    double ans = 0;//������ӵı�Ȩ��
    for(int i = 1;i <= cnt;i++) {
        node tmp = a[i];
        if(dis[getf(tmp.x)]!=dis[getf(tmp.y)]) {//����δ����������
            ans += tmp.z;//��ӱ�Ȩֵ
            dis[getf(tmp.x)] = dis[getf(tmp.y)];//����ϲ�
        }
    }
    printf("%.2f",ans);
    return 0;
}
