#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;

//��⣺�봫ֽ������
//��ά����dp
//���� ����,��һ��·����λ��,�ڶ���·����λ�� Ϊ״̬
//�߽磺������� (1,1)���ܴ���ֵ��������Ҫ��ʼ�����λ��
//�� dp[0][1][1] = a[1][1]
//ת�ƣ����ĸ�״̬ת�ƹ��������º����ң�2*2���
//ע���ж������λ�õ��������
//Ŀ��״̬��dp[n+n-2][n][n]

const int MAXN = 11;
int a[MAXN][MAXN],dp[MAXN*2][MAXN][MAXN];
int main() {
    int n,x,y,val;
    cin>>n;
    while(cin>>x>>y>>val&&x+y+val) {                    //��Ϊ0�����������
        a[x][y] = val;                                  //�洢��Ӧλ�õ�ֵ
    }
    dp[0][1][1] = a[1][1];                              //�߽�ֵ
    for(int step = 1;step <= n+n-2;step++) {            //��ʼ����1��ʼ
        for(int i = 1;i <= n&&i <= step+1;i++) {        //���ܳ���step+1
            for(int j = 1;j <= n&&j <= step+1;j++) {
                int ix = step+2-i;                      //�����Ӧ��λ��
                int jx = step+2-j;
                int one = max(dp[step-1][i][j], dp[step-1][i][j-1]);//�ֱ����
                int two = max(dp[step-1][i-1][j], dp[step-1][i-1][j-1]);
                dp[step][i][j] = max(one, two);         //��������ֱ���㣬�����©��������
                if(i==j) dp[step][i][j] += a[ix][i];    //�ص�ֻ�����һ��
                else dp[step][i][j] += a[ix][i]+a[jx][j];//�����������λ�õ�ֵ
            }
        }
    }
    cout<<dp[n+n-2][n][n];
    return 0;
}
