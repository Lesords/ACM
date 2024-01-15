#include<iostream>//ac
#include<iomanip>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x3f3f3f3f
#define two(x) (x)*(x)
using namespace std;

//��⣺״̬ѹ��DP
//�ȼ������е�֮��ľ���
//���ö����ƴ洢�Ѿ�������������λ��
//Ȼ�����DP

const int MAXN = 17;
double x[MAXN],y[MAXN],dis[MAXN][MAXN],f[MAXN][1<<15];//x��y�����¼����
//disΪ��¼����֮��ľ���
//f[i][j]������i��״̬Ϊj����С����
double cal(int i,int j) {//����i��j�ľ���
    return sqrt(two(x[i]-x[j]) + two(y[i]-y[j]));
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>x[i]>>y[i];
    }
    for(int i = 0;i <= n;i++) {             //���������ľ���
        for(int j = i+1;j <= n;j++) {
            dis[j][i] = dis[i][j] = cal(i,j);
        }
    }
    memset(f,0x7f,sizeof(f));               //��ֵΪ0x7f��Ϊ���ֵ������
    for(int i = 1;i <= n;i++) {             //�߽�״̬
        f[i][1<<(i-1)] = dis[0][i];         //ֻ����i��ľ���
    }
    for(int k = 1;k <= (1<<n)-1;k++) {      //��������״̬
        for(int i = 1;i <= n;i++) {         //��j�㵽i�㣡����
            if((k&(1<<(i-1)))==0) continue; //i�㻹û�б�����������
            for(int j = 1;j <= n;j++) {
                if(i==j) continue;          //������ͬ��
                // == ���ȼ��� & ��������Ҫ�����ţ�����
                if((k&(1<<(j-1)))==0) continue;//j�㻹û�б�����������������
                //�� ����j�㵫��û����i�� ��״̬ + i�㵽j��ľ���
                f[i][k] = min(f[i][k],f[j][k-(1<<(i-1))]+dis[i][j]);
            }
        }
    }
    double ans = INF;                       //��ʼ��Ϊ���ֵ
    for(int i = 1;i <= n;i++) {
        ans = min(ans, f[i][(1<<n)-1]);     //����i�������е㶼���ʹ�
    }
    printf("%.2f",ans);
    return 0;
}
