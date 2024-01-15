#include<iostream>//ac
#include<deque>
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����dp+���������Ż�
//������ĿҪ���ܳ���k�����������ֱ�ѡ��
//��ô�������Ϊ�ۼ��������ֺͣ��ټ�ȥÿ���ྭ��k�������κ������
//�� dp[i] Ϊѡ��i��ǰ�����ʱ����Ҫ�۳������ֺ�
//�߽�״̬��dp[0] = 0
//ת�ƹ��̣�dp[i] = a[i] + min(dp[j])  ���� i-k-1 <= j <= i-1
//Ҳ����˵��Զ��λ����i����k(����i-k-1λ��)��λ�ã������λ�þ���iǰ�棡����
//��ô���� i-k-1 <= j <= i-1 ������䣬���������������Ż�
//ÿ�����жϵ�ǰ�������Ƿ�ȶ�β��ֵС��Ȼ�����߳�������Χ��ֵ
//Ŀ��״̬��max(sum-f[i])  ���� n-k <= i <= n

const int MAXN = 1e5+5;
ll a[MAXN],f[MAXN];
int main() {
    int n,k;
    ll sum = 0,ans = 0;
    cin>>n>>k;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        sum += a[i];//�ۼӺ�
    }
    deque<int> de;
    de.push_back(0);//�߽��0����ֹԽ�磡����
    for(int i = 1;i <= n;i++) {
        f[i] = a[i]+f[de.front()];//��ǰ��+ǰ���ڷ�Χ�ڵ���Сֵ
        //��Ϊ�����������ֵ��f���飬�����ȼ���f��ֵ������
        //�����ǰֵ�ȶ�βС���򽫶�β����
        while(!de.empty()&&f[de.back()]>f[i]) de.pop_back();
        de.push_back(i);//���뵱ǰֵ
        //���׵�λ��Ҫ������һ��λ�� i+1 �ķ�Χ,������һ��λ���м�ֻ�ܸ�k��λ��
        while(!de.empty()&&de.front()+k+1<i+1) de.pop_front();
    }
    for(int i = n-k;i <= n;i++) {//n-k����պ�ʣ��k��λ�ã�����
        ans = max(ans, sum-f[i]);//ȡ���ֵ
    }
    cout<<ans;
    return 0;
}
