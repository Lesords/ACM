#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺dfs������ѡ�����룬Ȼ������ǰ׺���ж�����֦

const int MAXN = 1e3+5;
ll n,c,a[MAXN],sum[MAXN],ans;//sumΪǰ׺�����飬aΪԭ����
void dfs(ll pos,ll val) {//posΪ��ǰλ�ã�valΪ��ǰ����
    if(val>c) return;//��������������
    if(sum[pos-1]+val<=c) {//ǰ��ȫ��������������������´𰸣���֦������
        ans = max(ans, sum[pos-1]+val);
        return;
    }
    ans = max(ans, val);//���´�
    for(int i = 1;i < pos;i++) {//����ǰ�滹δѡ�������
        dfs(i, val+a[i]);//����λ�ã��Ͷ�Ӧֵ��ֻѡ���Ӧλ�õ����룡����
    }
}
int main() {
    cin>>n>>c;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        sum[i] = sum[i-1] + a[i];//ǰ׺�ʹ���
    }
    dfs(n+1,0);
    cout<<ans;
    return 0;
}
