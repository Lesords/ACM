#include<iostream>//ac
#include<cstring>
#include<algorithm>
using namespace std;

//��⣺����+���·
//���ñ�����Ԥ�����������Ƿ������1s�ڵ���
//Ȼ������floyd�����·�����ٻ���ʱ�䣩

int n,m;
int dis[55][55],f[55][55][55];
//dis[i][j]����ʾi��j�ľ���
//f[i][j][k]����ʾi��j���ھ���Ϊ 2^k ��·
int main() {
    memset(dis,0x3f,sizeof(dis));//��ʼ��Ϊ���ֵ
    cin>>n>>m;
    for(int i = 1;i <= m;i++) {//m���ߣ�wa�㣩������
        int x,y;
        cin>>x>>y;
        dis[x][y] = 1;//x��y�Ļ��ѵ�ʱ��
        f[x][y][0] = 1;//�����ı߽�
    }
    //����Ԥ�������һ�뵽��ĵ�
    for(int i = 1;i < 50;i++) {//������Χ
        for(int j = 1;j <= n;j++) {//�м��
            for(int k = 1;k <= n;k++) {//���
                for(int u = 1;u <= n;u++) {//�յ�
                    //����˼�룺һ���������������С�����
                    //2^i = 2^(i-1) + 2^(i-1)
                    if(f[k][j][i-1]&&f[j][u][i-1]) {
                        f[k][u][i] = 1;//��¼·��
                        dis[k][u] = 1;
                    }
                }
            }
        }
    }
    //floyd�����·�����ٻ���ʱ��ʱ�䣩
    for(int i = 1;i <= n;i++) {//�м��
        for(int j = 1;j <= n;j++) {//���
            for(int k = 1;k <= n;k++) {//�յ�
                dis[j][k] = min(dis[j][k], dis[j][i]+dis[i][k]);
            }
        }
    }
    cout<<dis[1][n];
    return 0;
}
