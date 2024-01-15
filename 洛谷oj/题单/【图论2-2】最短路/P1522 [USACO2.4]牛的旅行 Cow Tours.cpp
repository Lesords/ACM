#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define two(x) (x)*(x)
using namespace std;

//���⣺����n�����������꣬�Լ���n���������ڽӾ����ϵ��1Ϊ�бߣ�0�ޱߣ�
//���ڸպ����������������������������и�ѡһ���������ӣ�ʹ������������֮ͨ��
//��ֱ����С
//��⣺�ȼ������������ڵĸ�������֮������·
//Ȼ����ѡ��һ����������������������ֱ����С�ıߣ�ȡ������������ֵ��Ϊ����ֱ��

const int MAXN = 155;
struct node{
    double x,y;
}a[MAXN];
double dis[MAXN][MAXN],maxdis[MAXN];//dis��¼��������֮��ľ��룬maxdis��¼��ǰ����������Զ�����ľ���
double cal(int s,int e) {//����s��e�ľ���
    return sqrt(two(a[s].x-a[e].x) + two(a[s].y-a[e].y));
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].x>>a[i].y;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            char tmp;
            cin>>tmp;
            if(tmp=='1') {//1Ϊ�б�
                dis[i][j] = cal(i,j);
            }
            else if(i!=j) dis[i][j] = INF;
        }
    }
    for(int k = 1;k <= n;k++) {//floyd�����·
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    double ans = 0,joint = INF;//ans�ȼ��������ڸ�������������Զ����������
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(dis[i][j]!=INF) maxdis[i] = max(maxdis[i], dis[i][j]);//����i���Ե������Զ����
            ans = max(ans, maxdis[i]);//����ans
        }
    }
    for(int i = 1;i <= n;i++) {//Ѱ��û����ͨ�������㣬���ֱ�Ϊ��������������
        for(int j = 1;j <= n;j++) {
            if(dis[i][j]==INF) {//i��j����ͨ
                double val = cal(i,j);//����i��j�ľ���
                joint = min(joint, maxdis[i]+val+maxdis[j]);//��ͨ���ֱ��Ҫȡ��С������
                //i���Ե������Զ���� + ij���� + j���Ե������Զ���� = ��ͨ��������ֱ��
            }
        }
    }//�п�����֮ͨ���ֱ��joint�ȵ�������ansС��������Ҫ��ȡmax
    printf("%.6f",max(ans,joint));
    return 0;
}
