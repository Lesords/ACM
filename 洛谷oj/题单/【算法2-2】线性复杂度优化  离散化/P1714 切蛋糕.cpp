#include<iostream>//ac
#include<deque>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;

//��⣺��������
//������ά����Ӧ����ֵ��λ��
//���ڿ��ܳ��ֿ�ͷλ�ü�Ϊ���ֵ��������Ҫ���һ���߽�0
//�����г���λ��m�ĵ�������Ϊ���䳤��Ϊm������ǰ׺��������Ϊ������(���)�����԰���m
//��β��ǰ׺�ʹ��ڵ�ǰֵ����ô����
//��ΪҪ��ʹ����������ôǰ���ǰ׺�ͱ���ȡ��Сֵ������
//�����´�

const int MAXN = 5e5+5;
int n,m;
int a[MAXN], sum[MAXN];//aΪԭ���飬sumΪǰ׺������
int main() {
//    freopen("P1714_2.in", "r", stdin);
    fast;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        sum[i] = a[i]+sum[i-1];
    }
    deque<int> q;
    q.push_back(0);//�߽�λ��
    int ans = -INF;//����ָ������
    for(int i = 1;i <= n;i++) {
        //Խ�磬������q.front()����߽磨�����䣩�����Կ���Ϊm
        while(!q.empty()&&i-q.front()>m) q.pop_front();
        //��β���ڵ�ǰֵ������������С��
        while(!q.empty()&&sum[q.back()]>=sum[i]) q.pop_back();
        q.push_back(i);//��¼��ǰֵ
        ans = max(ans, sum[i]-sum[q.front()]);//���½��
    }
    cout<<ans<<"\n";
    return 0;
}
/*
10 8
500 -448 -431 86 -41 190 -46 -104 233 1
500
*/
