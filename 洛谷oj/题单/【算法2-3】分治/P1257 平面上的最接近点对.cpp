#include<iostream>//ac
#include<cstdio>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define two(x) (x)*(x)
using namespace std;
const int MAXN = 1e4+5;

//��⣺���Σ���ƽ���ϵĵ��Ȱ���x����Ȼ����y����
//ÿ����ƽ���ϵĵ�ֳ�������������
//���ֵı߽�Ϊ����ֻ��һ����������㣬һ����ֱ�ӷ���INF��������ֱ�ӷ���������֮��ľ���
//Ȼ��ȡ���������С�ľ���disΪ��׼�����м�����������ţ�����С�ڵ���dis�ĵ���뼯����
//���Ѽ����еĵ������Ƚϣ�ȡ��Сֵ

struct node{
    double x,y;
    friend bool operator < (node a,node b) {
        if(a.x!=b.x) return a.x < b.x;//�Ȱ������������ٰ�����������
        return a.y < b.y;
    }
}a[MAXN];
int b[MAXN];//��¼�����еĵ�ı��
double cal(int i,int j) {//����i��j�ľ���
    return sqrt(two(a[i].x-a[j].x) + two(a[i].y-a[j].y));
}
double Merge(int l,int r) {//����[l,r]����������������Сֵ
    double dis = INF;
    if(l==r) return dis;//ֻ��һ���㣬������
    if(l+1==r) {//��������ֱ�Ӽ���
        return cal(l,r);
    }
    int mid = (l+r)/2,cnt = 0;
    double ldis = Merge(l,mid);//�������������̾���
    double rdis = Merge(mid+1,r);//�������������̾���
    dis = min(ldis,rdis);//�ǵø���dis����Ȼ����ֵΪ�м伯�ϵ���С����룩������
    //�����м䲿�ֵĵ�
    for(int i = l;i <= r;i++) {
        double tdis = fabs(a[i].x-a[mid].x);//��a[mid].xΪ����
        if(tdis<=dis) {//С�ڵ���dis����ӵ���
            b[++cnt] = i;
        }
    }
    for(int i = 1;i <= cnt;i++) {//���㼯���ڵĵ�ľ���
        for(int j = i+1;j <= cnt;j++) {
            dis = min(dis, cal(b[i],b[j]));//ȡ��Сֵ
        }
    }
    return dis;
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        double x,y;
        cin>>x>>y;
        a[i] = {x,y};//��¼��
    }
    sort(a+1,a+1+n);//����
    printf("%.4lf",Merge(1,n));
    return 0;
}
