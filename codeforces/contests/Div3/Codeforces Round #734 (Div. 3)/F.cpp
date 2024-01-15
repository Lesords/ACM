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

//���⣺������ѡ��k���㣬ʹ����k�����໥֮��ľ�����ȣ����㷽����
//��⣺
//1. ���ֻѡ��������Ļ���Ҳ����˵��k=2ʱ�����Դ���������ѡ��������
//���������㶨����������������Ϊ c(n,2) = n*(n-1)/2;
//2. ���ѡ��ĵ�������2�Ļ���Ҳ����˵k>2ʱ
//��ôһ������һ����m����ÿ����֮���·��֮�䣬���Ҳ���ѡ��
//Ҳ����˵����mΪ���ڵ㣬ö��m���е�������ÿ���������ֻ��ѡ��һ���ڵ㣨Ҳ�ɲ�ѡ��
//�������ѡ��k���ڵ㣬�������еĽڵ�֮���LCA�����Ǹ��ڵ�m
//���Կ����������£�
//ö�����е�Ϊ���ڵ�ʱ����num[i][j]��¼ÿ���ڵ�i������j�����ܵ��������
//Ȼ��ö�����е����dep�����㵱ǰ���ڵ���dep����ѡ��k��ķ�����
//�� dp[i][j] Ϊ��i��������ѡ��j���ڵ�ķ�����
//�߽�Ϊ������dp��ʼ��Ϊ0����dp[i][0] = 1 ������  1 <= i <= n
//ת�ƹ��̣� ����ÿ�������У���ѡ����num[son][dep]���ڵ���ѡ��һ��
//dp[i][j] = dp[i-1][j] + dp[i-1][j-1]*num[son][dep]
//ע�⣺num[son][dep] Ϊ��ǰ���ӽڵ�son�������Ϊdep�Ľڵ�����
//��˿��ܱ�int��������ll���ǵ�ȡģ������
//Ŀ��״̬�����е� dp[��������][k] ���ȡģ

const int MAXN = 105;
const int MOD = 1e9+7;
vector<int> g[MAXN];//���
int n,k;
ll num[MAXN][MAXN],dp[MAXN][MAXN];
void dfs(int now, int fa) {                     //��ǰ��Ϊnow�����ڵ�Ϊfa
    num[now][0] = 1;                            //��¼��ǰ��
    for(int i = 0;i < g[now].size();i++) {      //��������ָ���
        int dot = g[now][i];                    //��ǰָ���
        if(dot==fa) continue;                   //�ظ���������
        dfs(dot, now);                          //�������±���
        for(int j = 1;j <= n;j++) {             //���¶�Ӧ����
            //��ǰnow�� j ���൱�ڶ��ӽڵ�dot�� j-1 ��
            num[now][j] += num[dot][j-1];
        }
    }
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i = 1;i <= n-1;i++) {
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);//��ߣ�˫���
            g[v].push_back(u);
        }
        if(k==2) {//����ѡ��2���ڵ�����
            for(int i = 1;i <= n;i++) g[i].clear();//��ձߣ�����
            cout<<n*(n-1)/2<<"\n";
            continue;
        }
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            memset(num, 0, sizeof(num));//��ʼ����������Ϊ0
            dfs(i,-1);
            int siz = g[i].size();//��������
            for(int dep = 0;dep <= n;dep++) {//��0��ʼ�������
                memset(dp, 0, sizeof(dp));//��ʼ��Ϊ0
                for(int j = 0;j <= siz;j++) dp[j][0] = 1;//�߽�Ϊ1
                for(int j = 1;j <= siz;j++) {//������������
                    for(int k = 1;k <= j;k++) {//����ѡ����������ܳ�����������������
                        int son = g[i][j-1];//�±��0��ʼ��������-1
                        int val = num[son][dep];//��ǰ��������ѡ�������
                        //����dp[j][k]��Ϊ ��ѡ �� ѡ
                        dp[j][k] = (dp[j-1][k]+dp[j-1][k-1]*val%MOD)%MOD;
                    }
                }
                ans = (ans+dp[siz][k])%MOD;//�ۼӺͲ�ȡģ
            }
        }
        cout<<ans<<"\n";
        for(int i = 1;i <= n;i++) g[i].clear();//��ձߣ�����
    }
    return 0;
}
