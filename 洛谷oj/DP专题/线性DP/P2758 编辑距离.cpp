#include<iostream>//ac
#include<string>
#include<algorithm>
using namespace std;

//��⣺����dp
//�� dp[i][j] Ϊ���ַ���a��ǰi��ƥ�䵽�ַ���b��ǰj�������ѵĴ���
//�߽�״̬��dp[i][0], dp[0][i] (1 <= i <= [len_a,len_b])
//dp[i][0] = i����ɾ��i���ַ�����dp[0][i] = i�������i���ַ���
//ת�ƣ���������ַ���������������dp[i][j] = dp[i-1][j-1]
//�������ɾ����ǰ�ַ� dp[i-1][j] + 1
//        ����һ���ַ� dp[i][j-1] + 1
//        ���ĵ�ǰ�ַ� dp[i-1][j-1] + 1
//�������ȡ��Сֵ
//Ŀ��״̬��dp[len_a][len_b]

const int MAXN = 2e3+5;
char s1[MAXN], s2[MAXN];
int dp[MAXN][MAXN];
int main() {
    string a,b;
    cin>>a>>b;
    int len_a = a.size();
    int len_b = b.size();
    //���ַ���ת��Ϊ�ַ����飬����ʼ���߽����
    for(int i = 0;i < len_a;i++) s1[i+1] = a[i], dp[i+1][0] = i+1;
    for(int i = 0;i < len_b;i++) s2[i+1] = b[i], dp[0][i+1] = i+1;
    for(int i = 1;i <= len_a;i++) {
        for(int j = 1;j <= len_b;j++) {
            if(s1[i]==s2[j]) dp[i][j] = dp[i-1][j-1];//����������
            else {
                //������������ȡ��Сֵ
                dp[i][j] = min(min(dp[i-1][j]+1, dp[i][j-1]+1), dp[i-1][j-1]+1);
            }
        }
    }
    cout<<dp[len_a][len_b];
    return 0;
}
