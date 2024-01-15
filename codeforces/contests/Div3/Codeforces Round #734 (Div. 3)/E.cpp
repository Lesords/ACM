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

//��⣺����dp
//�� dp[i][j] Ϊǰi��ʣ��j��ʱ��ֵ���±�ƥ����������
//�߽�״̬�������������0����Ϊdp�洢��ƥ����������ʼ��ȫΪ0��û��1���������!

//״̬ת�ƣ��������е����֣�ÿ������������ѡ��ɾ�Ͳ�ɾ
//1. ��ɾ������ dp[i][j] = max(dp[i][j], dp[i-1][j]);
//2. ����ɾ������Ҫ�жϵ�ǰֵ�Ƿ�Ϊ j����Ϊʣ��j�������Ե�ǰֵ�����꼴Ϊj
//����ȣ���ֵ��+1
//���� dp[i][j] = max(dp[i][j], dp[i-1][j-1] + a[i]==j);

//Ŀ��״̬��������Ҫʹ��������С����ƥ������Ҫ���ڵ���k
//���Կ��Ա��� dp[n][i],���� 0 <= i <= n
//Ѱ������Ĳ�������С�����������iΪʣ����������n-iΪ��������
//Ҫʹ����������С����i��Ҫ�ϴ����Կ��Ե���������ҵ��ĵ�һ����Ϊ���

const int MAXN = 2e3+5;
const int MOD = 1e9+7;
int dp[MAXN][MAXN],a[MAXN];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        memset(dp, 0, sizeof(dp));//��ʼ����Ϊ0
        int n,k;
        cin>>n>>k;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= i;j++) {//j���ܳ���i������������
                //��ɾ����Ҫ�жϵ�ǰֵ�Ƿ����j
                dp[i][j] = max(dp[i][j], dp[i-1][j-1]+(a[i]==j));
                //ɾ
                dp[i][j] = max(dp[i][j], dp[i-1][j]);
            }
        }
        int ans = -1;//��ʼ��Ϊ-1����ʾ�޽�
        for(int i = n;i >= 0;i--) {
            if(dp[n][i]>=k) {//����Ѱ�ң���һ����Ϊ��
                ans = n-i;//iΪʣ��������n-iΪ��������
                break;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
