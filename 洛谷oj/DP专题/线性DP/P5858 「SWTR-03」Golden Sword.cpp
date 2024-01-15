#include<iostream>//ac
#include<queue>
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

//��⣺����dp+���������Ż�
//�� dp[i][j] ��ʾ��ǰѡ��iԭ�ϣ��������������j��ԭ��ʱ���;ö�
//����ԭ���;ö��и�����������Ҫ������״̬��ֵΪ-INF
//�߽�״̬��dp[0][0] = 0������ʱû��ԭ�����;ö�Ϊ0
//״̬ת�ƣ�
// dp[i][j] = a[i]*j + min(dp[i-1][k]) (j-1<= k < j+s)
//��ǰԭ���;ö� + ��һ��״̬��ֵ
//����ÿ��ֻ��ȡ��s��ԭ�ϣ����Ե�ǰҪôһ��ûȡ��(j-1)��Ҫôȡ����s����j+s-1��
//��Ϊ (j-1)+1 = j; (j+s-1) - s + 1 = j;��ȡ����Ӧ����+��ǰһ����
//���Զ���һ������Ϊs���ȵ�dp״̬ȡminֵ
//��ô�����õ����������Ż��������
//����������һ��j�������ȵ�ǰ�����ж���j��״̬���Ե�����㣡����
//ÿ�γ�ʼ״̬�ȷ��뱾��λ�õ�ֵ��Ȼ���ٽ����ж��Ƿ���Խ��ģ�Ȼ���ٷ���j-1��ֵ
//�����պ������˷�Χ����
//Ŀ��״̬��max(dp[n][i])  1 <= i <= w

const int MAXN = 5e3+5;
struct node{
    int pos;//��¼λ��
    ll val;//��¼ֵ
};
ll dp[MAXN][MAXN],a[MAXN];
int main() {
    int n,w,s;
    cin>>n>>w>>s;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 0;i <= n;i++) {//��ֵΪ��Сֵ-INF
        for(int j = 0;j <= w;j++) dp[i][j] = -INF;
    }
    dp[0][0] = 0;//�߽�״̬Ϊ0
    deque<node> de;//˫�˶�����ʵ�ֵ�������
    for(int i = 1;i <= n;i++) {
        while(!de.empty()) de.pop_back();//��ն���
        //�����ʼֵ������ֻ������w����������Ҫȡ��Сֵ������
        de.push_back({min(i,w),dp[i-1][min(i,w)]});
        for(int j = min(i,w);j >= 1;j--) {//������㣬�����������ɸ�ԭ�ϵ�����
            //�������s��ԭ�Ϻ󣬲��ܳ���j-1��Ԥ��һ��������1�������򵯳�
            //ע�⣺��Ҫ�ж϶����Ƿ�Ϊ�գ�����
            while(!de.empty()&&de.front().pos-s>j-1) de.pop_front();
            //���ڵ�ǰ��ӵ�״̬Ϊdp[i-1][j-1]�����Խ����������б���С�ĵ���
            while(!de.empty()&&de.back().val<dp[i-1][j-1]) de.pop_back();
            de.push_back({j-1, dp[i-1][j-1]});
            dp[i][j] = a[i]*j+de.front().val;
        }
    }
    ll ans = -INF;//������
    for(int i = 1;i <= w;i++) ans = max(ans, dp[n][i]);//ȡ���ֵ
    cout<<ans;
    return 0;
}
