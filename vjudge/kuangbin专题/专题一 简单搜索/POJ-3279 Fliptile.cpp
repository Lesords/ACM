#include<iostream>//ac  ״̬ѹ��
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺״̬ѹ������ö�ٵ�һ�е�״̬
//Ȼ���������ÿһ�е�״̬������һ�о���������ж����һ���Ƿ�������������
//ע�⣺��Ҫ�ȼ�¼��С�ķ�ת������Ȼ������ֵ���

int n,m,a[20][20],op[20][20],b[20][20],ans[20][20];//ans�������Ĳ���
//zΪԭ���飬bΪ�м�洢���飬opΪ��ǰ����
int nextt[4][2] = {0,1,0,-1,1,0,-1,0};
void change(int x,int y) {//��ת��ǰλ�ü���Χ�ĸ�����λ�õ�ֵ
    b[x][y] ^= 1;// ^1��Ϊȡ��
    for(int i = 0;i < 4;i++) {
        int tx = x+nextt[i][0];
        int ty = y+nextt[i][1];
        if(tx<1||tx>n||ty<1||ty>m) continue;//����Խ��
        b[tx][ty] ^= 1;
    }
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin>>a[i][j];
        }
    }
    int num = INF;//num��¼���ٵķ�ת����
    for(int i = 0;i < (1<<m);i++) {//ö������״̬��״̬ѹ����
        int cnt = 0;//cnt��¼��ǰ��ת�Ĵ���
        for(int j = 1;j <= n;j++)//��ʼ��
            for(int k = 1;k <= m;k++) b[j][k] = a[j][k],op[j][k] = 0;
        for(int j = 0;j < m;j++) {//�����ֵ����ұ�Ϊ��λ������
            op[1][m-j] = (i>>j)&1;//�жϵ�jλ�Ƿ�Ϊ1����0λ��ʼλ��
            if(op[1][m-j]) change(1,m-j),cnt++;
        }
        for(int j = 2;j <= n;j++) {//�ӵڶ��п�ʼ�жϣ�Ҫ�жϵ����һ�У�����
            for(int k = 1;k <= m;k++) {//�ж���һ�е�ֵ
                if(b[j-1][k]) op[j][k] = 1,change(j,k),cnt++;
            }//ֵΪ1����Ҫ��ת
        }
        int ff = 0;
        for(int j = 1;j <= m;j++) if(b[n][j]) {//�ж����һ���Ƿ����1
            ff = 1;break;//��������������
        }
        if(ff) continue;
        if(cnt<num) {//������Сֵ
            num = cnt;
            for(int j = 1;j <= n;j++)//���²�������
                for(int k = 1;k <= m;k++) ans[j][k] = op[j][k];
        }
    }
    if(num==INF) cout<<"IMPOSSIBLE\n";//INF��Ϊ�޽�
    else for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(j!=1) cout<<" ";
            cout<<ans[i][j];
        }
        cout<<"\n";
    }
    return 0;
}
/*
�޽��������
4 4
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 1
*/
