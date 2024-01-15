#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺����dp
//�����������Ҫ��С����ô��Ҫ��С�������������Ҫ���ѵ�ʱ��
//�� ��ǰʱ�䣬��ѡ����� Ϊ״̬
//��ʼ���߽磺
//�Ƚ�ȫ����ֵΪINF��Ȼ��ÿ��ʱ����ó�0������(dp[i][0])��״̬�޸�Ϊ0
//��ô����˳��ʱ����ת�Ʒ����ˣ�����ʱ�乻ת��
//������ dp[i][j]����ʾ��iʱ���Ѿ��ó���j�����ӵ���Сֵ
//��ô���iʱ��ǰ�Ѿ��ó���j�����ӵ�״̬Ҳ���԰����� dp[i][j]��
//�� dp[i][j] = min(dp[i][j], dp[i-1][j]) ������
//���Ǽ̳�ǰ���״̬
//��ô���ڵ�ǰ��ѡ��j���ӵĻ�Ϊ��
//dp[i][j] = min(dp[i][j], dp[i-1][j-1] + abs(t[j]-i))
//���״̬��
//��ô���� ÿ��ʱ����ó���n�����ӵ�״̬(dp[i][n]) ȡ��Сֵ����

const int MAXN = 205;
int t[MAXN],dp[MAXN<<1][MAXN];//��һάΪʱ�䣬������
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int q;
    cin>>q;
    while(q--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>t[i];
        sort(t+1,t+1+n);                    //����
        memset(dp,0x3f,sizeof(dp));         //��ֵΪINF
        for(int i = 0;i <= n*2;i++) dp[i][0] = 0; //�߽�״̬Ϊ0��û�ó�����
        for(int i = 1;i <= n*2;i++) {       //��ʱ�䣬��Ҫ�̳�ǰ���ʱ�䣬�����޷��̳У�����
            for(int j = 1;j <= n;j++) {     //�������е���
                dp[i][j] = min(dp[i][j], dp[i-1][j]);                   //�̳�ǰ���״̬
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]+abs(t[j]-i));     //��ǰѡ��
            }
        }
        int ans = INF;                                                  //��������ʱ���
        for(int i = 1;i <= n*2;i++) ans = min(ans, dp[i][n]);           //ȡ��Сֵ����
        cout<<ans<<'\n';
    }
	return 0;
}
