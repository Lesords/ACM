#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺����dp
//������ [��߽�,�ұ߽�] Ϊ״̬
//dp[i][j]Ϊ����[i,j]�ڿ��Ժϳɵ������ֵ
//�߽����Ϊû�кϲ���ʱ��ֵΪ����
//ÿ�κϲ����������ʱ����Ҫ �ж����������ֵ�Ƿ���ͬ
//ÿ�κϲ���ʱ�򶼿��Ը��´𰸣�ȡ���ֵ����

const int MAXN = 256;
int a[MAXN],dp[MAXN][MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        dp[i][i] = a[i];//�߽������ֵΪ����
    }
    int ans = 0;
    for(int len = 1;len < n;len++) {            //�ȳ���
        for(int i = 1;i+len <= n;i++) {         //�����
            int j = i+len;                      //�յ�ɼ���
            for(int k = i;k < j;k++) {          //���������м��
                if(dp[i][k]==dp[k+1][j]) {      //���������ֵ��Ҫ��ͬ�ſ��Ժϲ�
                    dp[i][j] = max(dp[i][j], dp[i][k]+1);//���½ϴ�ֵ���ϲ���ֵ+1
                    ans = max(ans, dp[i][j]);   //���½ϴ�ֵ
                }
            }
        }
    }
    cout<<ans;
    return 0;
}
