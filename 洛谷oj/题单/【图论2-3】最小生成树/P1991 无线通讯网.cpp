#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<algorithm>
#define two(x) (x)*(x)
using namespace std;

//��⣺�������ǵ绰֮��ľ���Ϊ0������Զ�����������ǵ绰
//��ô���ڱ�����ԣ��������ɽ�һ���������ֳ����ɸ�����
//ÿ�����ֶ���һ�����ǵ绰�����Կ������������а���ļ����߷ָ��
//����s�����ǵ绰������Էָ�s-1���ߣ���s-1����Ϊ0��
//����p������������Ҫp-1����
//���Զ�����������˵ֻ��Ҫȡ (p-1)-(s-1) ����
//����ԭͼ��Kruskal�㷨��ȡ(p-1)-(s-1)���߾ͽ���
//ע�⣺��������ı�Ȩֵ���������ܺͣ�����

const int MAXN = 505;
struct node{
    int u,v;
    double w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;//���ȱ�ȨС��
    }
}a[MAXN*MAXN];
double x[MAXN],y[MAXN];//��¼����
int dis[MAXN];//��¼����
double cal(int i,int j) {//����i��j�ľ���
    return sqrt(two(x[i]-x[j])+two(y[i]-y[j]));
}
int getf(int p) {//Ѱ��p�����ȣ�·��ѹ��
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int s,p,cnt = 0;//cnt��¼����
    cin>>s>>p;
    for(int i = 1;i <= p;i++) cin>>x[i]>>y[i];
    for(int i = 1;i <= p;i++) {
        for(int j = i+1;j <= p;j++) {
            //ֻȡһ������ı�
            a[++cnt] = {i,j,cal(i,j)};//���
        }
        dis[i] = i;//��ʼ������Ϊ����
    }
    sort(a+1,a+1+cnt);
    double ans = 0;
    int num = (p-1)-(s-1);//��Ҫ����ı���
    for(int i = 1;i <= cnt;i++) {//�������б�
        node tmp = a[i];
        if(getf(tmp.u)!=getf(tmp.v)) {//�������������У�������
            dis[getf(tmp.u)] = dis[getf(tmp.v)];
            num--;//����--
            if(num==0) {//Ϊ0˵��û��ѡ�ˣ����´𰸺����
                ans = tmp.w;//��ǰ��Ȩ��Ϊ����Ȩֵ
                break;
            }
        }
    }
    printf("%.2f",ans);
    return 0;
}
