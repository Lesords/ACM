#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define two(x) (x)*(x)
using namespace std;

//��⣺���ȼ�������Ұ��֮��ľ���
//������ЩҰ�˷ֳ���k�����䣬��ô�������Ϊ��һ���������ֳ�k������
//����һ��n�������������Ҫ���� n-1 ����
//���������ֳ�k��������Ҫ�۳� k-1 ����
//��Ұ�˵���һ���㣬���Զ���Щ����Ҫ���� (n-1) - (k-1) = n-k ���߼���
//������Ŀ��Ҫ�������������֮�����С����
//��ô�����С���뼴Ϊ���Ƿָ�ʱ����С�ߣ���Ϊ��С�������� n-k+1 С�ı�
//Ҳ����˵������ѡ���� n-k ����С�ıߣ����� n-k+1 С�ı�ûѡ
//����Ϊ�˷ָ���������

const int MAXN = 1e3+5;
struct node{
    int u,v;
    double w;
    friend bool operator < (node a,node b) {
        return a.w < b.w;//��Ȩ��С��������
    }
}a[MAXN*MAXN];
int dis[MAXN];//��¼����
double x[MAXN],y[MAXN];//��¼����
double cal(int i,int j) {//����i��j�ľ���
    return sqrt(two(x[i]-x[j])+two(y[i]-y[j]));
}
int getf(int p) {//Ѱ��p�����ȣ�·��ѹ��
    return dis[p]==p?p:dis[p]=getf(dis[p]);
}
int main() {
    int n,k,cnt = 0;//cnt��¼�ߵ�����
    cin>>n>>k;
    for(int i = 1;i <= n;i++) {
        cin>>x[i]>>y[i];
        dis[i] = i;//��ʼ������Ϊ����
    }
    for(int i = 1;i <= n;i++) {
        for(int j = i+1;j <= n;j++) {
            //ֻȡһ������ıߣ���Ϊi��j�ľ������j��i�ľ��룩
            a[++cnt] = {i,j,cal(i,j)};
        }
    }
    sort(a+1,a+1+cnt);
    int num = 0;//numΪ�Ѿ�ѡ��ıߵ�����
    double ans = 0;//ansΪ����֮�����̾���
    for(int i = 1;i <= cnt;i++) {
        node tmp = a[i];
        if(getf(tmp.u)!=getf(tmp.v)) {//�������㻹δ����
            dis[getf(tmp.u)] = dis[getf(tmp.v)];//����ϲ�
            num++;//����++
            if(num==n-k+1) {//��ǰΪ n-k+1 С�ı�ʱ����Ϊ��������̾���
                ans = a[i].w;
                break;
            }
        }
    }
    printf("%.2f",ans);
    return 0;
}
