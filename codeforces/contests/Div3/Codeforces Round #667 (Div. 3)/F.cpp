#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺����dp����ǰ������״̬���������յ�״̬�� (n+1)
//������Ŀ��֪����Ҫƥ����ַ�ֻ������
//���Ե���ǰΪ t0 �ַ�ʱ����Ҫ�ж� t0��t1 �Ƿ���ȣ�����ȣ����ǰ��� t0 ��ƥ��
//����ǰ�ַ�Ϊ t1 �ַ�ʱ��ֱ�����ǰ��� cnt��t0 ����
//�������������������״̬���̼���
//��Ҫ�� ����ʼλ�������״̬��ֵΪ -1����ʾ��ֵ
//��Ӧ��̬�滮�����У�ֻ��������������޸ĵ�ǰ�ַ����޸ĵ�ǰ�ַ�Ϊt0���޸ĵ�ǰ�ַ�Ϊt1

const int MAXN = 205;
char s[MAXN],t[4];
int dp[MAXN][MAXN][MAXN];//dp[i][j][k]��ʾǰ(i-1)���޸�j���ַ�ӵ��k��t0�����ƥ����
int main() {
    memset(dp,-1,sizeof(dp));//��ʼ��Ϊ-1����ʾ����״̬��û��ֵ
    int n,k;
    cin>>n>>k>>s+1>>t;
    dp[1][0][0] = 0;//��ʼ����ʼ״̬Ϊ0���ڵ�һ���ַ���λ��0�β���0��t0��ƥ����Ϊ0
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j <= k;j++) {//��������0��ʼ����k����
            for(int cnt = 0;cnt <= n;cnt++) {//t0������0��ʼ����n����
                //�����ǰ��λ��Ϊ-1����ʾ��ǰ״̬û�г��ֹ�����ֱ������
                if(dp[i][j][cnt]==-1) continue;
                int e0 = s[i] == t[0];//�жϵ�ǰλ���Ƿ�Ϊt0
                int e1 = s[i] == t[1];//�жϵ�ǰλ���Ƿ�Ϊt1
                int e01 = t[0] == t[1];//�ж�t0��t1�Ƿ����
                //��i���ַ����޸ı����ֵ�� (i+1) λ�ã�����
                //��ǰ���޸��ַ�   ����ǰλ����Ϊ t1����ǰ��� cnt ��t0����ƥ��ɹ�
                dp[i+1][j][cnt+e0] = max(dp[i+1][j][cnt+e0], dp[i][j][cnt]+(e1?cnt:0));
                if(j<k) {
                    //����ǰ�ַ��޸�Ϊt0    ����t0��t1��ȣ���ǰ�� cnt��t0 �͵�ǰ��t0����ƥ��
                    dp[i+1][j+1][cnt+1] = max(dp[i+1][j+1][cnt+1], dp[i][j][cnt]+(e01?cnt:0));
                    //����ǰ�ַ��޸�Ϊt1    ����ǰλ��Ϊt1����ֱ�����ǰ��� cnt��t0 ����
                    dp[i+1][j+1][cnt+e01] = max(dp[i+1][j+1][cnt+e01], dp[i][j][cnt]+cnt);
                }
            }
        }
    }
    int ans = 0;
    for(int i = 0;i <= k;i++) {
        for(int cnt = 0;cnt <= n;cnt++) {
            //״̬�� n+1 ������
            ans = max(ans, dp[n+1][i][cnt]);//�������ֵ
        }
    }
    cout<<ans;
	return 0;
}
