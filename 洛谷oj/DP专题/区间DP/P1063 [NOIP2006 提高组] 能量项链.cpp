#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺����dp
//���������ǻ��Σ����Կ��Զ����һ�����������
//Ϊ�˷�����������ά��ÿ�����ӵ�ͷ��Ǻ�β��ǵ�ֵ
//��ô����ÿ�κϲ������ӵ�����Ϊ ȡ�׵�ͷ���*�м��β���*���һ����β���
//��Ҫע�������������Ҳ��Ҫ�ϲ���Ҳ����len��Ҫ��1��ʼ������
//��  [��߽�,�ұ߽�]  Ϊ��ǰ״̬
//f[i][j]Ϊ[i,j]�߽��ھۺϳ�һ�����Ӻ��ͷŵ��������
//ÿ�κϲ�������ȡ���ֵ ���� ֱ����nΪ���ȵ���������ȡ���ֵ

const int MAXN = 205;
int head[MAXN],tail[MAXN];//headΪͷ��ǣ�tailΪβ���
unsigned int dp[MAXN][MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>head[i];
        head[i+n] = head[i];                    //�����һ��
    }
    tail[2*n] = head[1];                        //�߽��β���
    for(int i = 1;i < 2*n;i++) {
        tail[i] = head[i+1];                    //����β���
    }
    unsigned int ans = 0;
    for(int len = 1;len < n;len++) {            //�ȳ���
        for(int i = 1;i+len <= 2*n;i++) {       //Ȼ�����
            int j = i+len;                      //�յ���Լ���
            for(int k = i;k < j;k++) {          //���������м�㣬���԰���i���ǲ��ܰ���j
                //���� k+1 �����j
                dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]+head[i]*tail[k]*tail[j]);
                //��ʱ�м��Ϊk
//                ans = max(ans, dp[i][j]);
            }
        }
    }
    for(int i = 1;i <= n;i++) ans = max(ans, dp[i][i+n-1]);//���ֶ���
    cout<<ans;
    return 0;
}
