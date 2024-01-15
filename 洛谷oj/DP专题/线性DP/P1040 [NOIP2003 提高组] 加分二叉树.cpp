#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����dp
//������Ŀ���������������
//����˵���Ƕ�������������ȡ�����ڵ㣬���ڵ��ֵ����������������˵�ֵ����
//�������ǰ�����������ÿ�μ��������ȡ����ĸ��ڵ㼴��
//�߽�״̬��dp[i][i] = a[i] �����ڵ�ֵΪ����
//״̬: [l,r] ��ʾ������[l,r]��������ֵ
//ת�ƣ�dp[i][k-1]*dp[k+1][j] + dp[k][k],  i < k < j
//���и�Ϊi��jλ�õ�ʱ��
//Ŀ��״̬��dp[1][n]

const int MAXN = 33;
int a[MAXN],root[MAXN][MAXN];//root��¼��Ӧ����ĸ��ڵ�
ll dp[MAXN][MAXN];
void print_path(int l,int r,int flag) {//���l��r�����ǰ�������flag�ж��Ƿ�����ո�
    if(l>r) return ;
    if(flag) cout<<" ";//���˵�һ��λ�ã�������Ҫ����ո�
    cout<<root[l][r];
    if(l==r) return;//��ΪҶ�ӣ�ֱ�ӷ���
    print_path(l, root[l][r]-1,1);//������
    print_path(root[l][r]+1, r,1);//������
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        dp[i][i] = a[i];                //�߽�״̬
        root[i][i] = i;                 //��¼���ڵ�Ϊ����
    }
    for(int len = 1;len < n;len++) {    //�ȳ���
        for(int i = 1;i <= n;i++) {     //�����
            int j = i+len;              //�����յ�
            dp[i][j] = dp[i][i]+dp[i+1][j];//��ȡiΪ���ڵ�
            root[i][j] = i;             //��¼���ڵ�
            for(int k = i+1;k <= j;k++) {//�������䣬�ǰ��Ϊ���ڵ�
                if(k==j) {              //�����һ����Ϊ���ڵ㣬���У�����
                    if(dp[i][j] < dp[k][k]+dp[i][k-1]) {
                        dp[i][j] = dp[k][k]+dp[i][k-1];//ȡ��Сֵ
                        root[i][j] = k; //���¸��ڵ�
                    }
                }
                else {
                    if(dp[i][j] < dp[k][k]+dp[i][k-1]*dp[k+1][j]) {
                        dp[i][j] = dp[i][k-1]*dp[k+1][j] + dp[k][k];
                        root[i][j] = k; //���·��������ڵ���
                    }
                }
            }
        }
    }
    cout<<dp[1][n]<<"\n";
    print_path(1,n,0);//�������
    return 0;
}
