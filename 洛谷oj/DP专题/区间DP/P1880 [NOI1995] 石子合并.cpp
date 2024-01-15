#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺����dp
//ע�⣺��Ŀ�е�ʯ���ǻ��εģ�������Ҫ�ظ�һ��ʯ�ӣ�����¼���ε����
//���ڶ������һ���������������ģ����Լ�������䳤�Ȼ���Ϊn������
//�� ����[l,r] Ϊ״̬
//�������� l <= k < r��ȡ��Ӧ����Сֵ�����ֵ
//ȡ��Сֵ��ʱ����Ҫ�������ʼ��Ϊ���ֵ���߽������ʼ��Ϊ0
//�߽����Ϊ��������ϲ���������Ҫ�ϲ����÷�Ϊ0

const int MAXN = 205;
int a[MAXN],sum[MAXN],f_up[MAXN][MAXN],f_down[MAXN][MAXN];
//aΪԭ���У�sumΪǰ׺������
//f_up[i][j]��Ϊ����[i,j]�ϲ���һ�ѻ��ѵ����÷�
//f_down[i][j]��Ϊ����[i,j]�ϲ���һ�ѻ��ѵ���С�÷�
int main() {
    memset(f_down, 0x3f, sizeof(f_down));   //��ʼ��Ϊ���ֵ
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        sum[i] = sum[i-1]+a[i];             //��¼ǰ׺��
        f_down[i][i] = 0;                   //�߽�ֵΪ0
    }
    for(int i = n+1;i <= n*2;i++) {         //�ظ�һ��
        a[i] = a[i-n];                      //��¼��Ӧֵ
        sum[i] = sum[i-1]+a[i];             //ǰ׺��
        f_down[i][i] = 0;                   //�߽�ֵΪ0
    }
    for(int len = 1;len < n;len++) {        //�ȱ��������С
        for(int i = 1;i+len <= n*2;i++) {   //������㣬�ж��²���Խ��
            int j = i+len;                  //�յ����ֱ�Ӽ���
            for(int k = i;k < j;k++) {      //�м�ķָ�㣬�ָ����԰�����㵫�������յ㣡����
                //�����Ӧ����С�÷ֺ����÷�
                f_down[i][j] = min(f_down[i][j], f_down[i][k]+f_down[k+1][j]+sum[j]-sum[i-1]);
                f_up[i][j] = max(f_up[i][j], f_up[i][k]+f_up[k+1][j]+sum[j]-sum[i-1]);
            }
        }
    }
    int ans_min = INF,ans_max = 0;
    for(int i = 1;i <= n;i++) {             //ȡÿ��iΪ����ҳ���Ϊn���������ֵ����
        ans_min = min(ans_min, f_down[i][i+n-1]);//���䳤��Ϊn����Ϊ[i,i+n-1]������
        ans_max = max(ans_max, f_up[i][i+n-1]);
    }
    cout<<ans_min<<"\n"<<ans_max;
    return 0;
}
