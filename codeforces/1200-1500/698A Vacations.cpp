#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 105;

//��⣺����ÿ����˵������״̬����Ϣ���˶������� (0 1 2)
//��ô���Ը��ݵ�������������Ӧ��״̬����

int a[MAXN],dp[MAXN][3];//dp[i][0|1|2]��Ϊ��ǰ״̬����Ϣ��������
int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
    memset(dp, 127, sizeof(dp));//��Сֵ�����ʼ����ֵ
    dp[0][0] = dp[0][1] = dp[0][2] = 0;//�ٽ����Ϊ0
    for(int i = 1;i <= n;i++) {
        //��ǰ��Ϣ����ǰһ���״̬�����ޣ�����״̬���ɣ�ȡСֵ + 1��
        dp[i][0] = min(dp[i-1][0], min(dp[i-1][1],dp[i-1][2])) + 1;
        if(a[i]==1||a[i]==3) {//����
            //����״̬��������������ȡǰһ�����������״̬�Ľ�Сֵ
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
        }
        if(a[i]==2||a[i]==3) {//�˶�
            //����״̬��������������ȡǰһ�����������״̬�Ľ�Сֵ
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
        }
    }
    //�յ�����״̬����Сֵ��Ϊ��
    printf("%d", min(dp[n][0], min(dp[n][1],dp[n][2])));
    return 0;
}
