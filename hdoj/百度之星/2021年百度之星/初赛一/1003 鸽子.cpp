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
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺����dp+��������
//�� dp[i][j] ��ʾִ�е���i������ʱ�����ĵ�����jλ�õ����ٲ�ִ�д���
//�߽磺����λ���ȳ�ʼ��ΪINF��Ȼ����dp[0][k] = 0����ʼ�㣩
//ת�Ʒ��̣�����ÿ��ֻ��һ������ (u,v) ��ʾu��v����
//����ת�Ʒ���Ϊ�� dp[i][u] = min(dp[i-1][v], dp[i-1][u]+1)   ִ�У���ִ��
//                 dp[i][u] = min(dp[i-1][u], dp[i-1][v]+1)
//Ŀ��״̬��dp[n][i] ���� 1 <= i <= n
//����ÿ��ת��ֻ����һ��״̬�йأ����Կ����ù�������ѵ�һά�Ż�������ʡ�ռ�

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
int dp[MAXN];//dp[i]: ��ʾִ�е���ǰ����ʱ����������iλ�õ����ٲ�ִ�д���
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        memset(dp, 0x3f,sizeof(dp));//��ʼ��ΪINF
        int n,m,k;
        scanf("%d%d%d", &n,&m,&k);
        dp[k] = 0;//���kΪ0������
        while(m--) {
            int u,v;
            scanf("%d%d", &u,&v);
            int last_u = dp[u],last_v = dp[v];//���������������洢��һ��״̬��ֵ������
            dp[u] = min(last_v, last_u+1);//ִ��  ��ִ��
            dp[v] = min(last_u, last_v+1);
        }
        for(int i = 1;i <= n;i++) {
            if(i!=1) printf(" ");
            if(dp[i]==INF) printf("-1");//INF��ʾ�޷���������-1
            else printf("%d", dp[i]);
        }
        puts("");
    }
	return 0;
}
