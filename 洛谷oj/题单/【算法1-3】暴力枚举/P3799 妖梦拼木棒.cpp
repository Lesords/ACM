#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺�ĸ�ľ������������Σ����Ա���������ľ����ȣ���������������������
//���ݷ�Χֻ��5e3�����Կ���ֱ��ö�� ��ͬ��ľ�� �� ƴ�ӵ�ľ��

const int MAXN = 5e3+5;
const ll MOD = 1e9+7;
ll num[MAXN];//��¼ÿ�ֳ��ȵ�ľ�����ֵĴ���
ll solve(ll num) {//��num��ľ����ѡ��2���������
    //c(2,num) = a(2,num)/a(2,2) = num*(num-1) / 2;
    return num*(num-1ll)/2%MOD;//�����ȳ�2��������ȡ��������
}
int main() {
    int n,tmp,maxx = 0;//maxx��¼���ľ������
    ll ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>tmp,num[tmp]++;//��¼ľ�����ֵĴ���
        maxx = max(tmp,maxx);
    }
    for(int i = 2;i <= maxx;i++) {//ö����ͬ��ľ��
        if(num[i]<2) continue;//������������
        ll tri = solve(num[i])%MOD;//������ͬľ���������
        for(int j = 1;j <= i/2;j++) {//��1������һ��
            //ƴ�ӵ�ľ����ͬ
            if(j*2==i&&num[j]>=2) ans += tri*solve(num[j])%MOD;
            //ƴ�ӵ�ľ������ͬ
            if(j*2!=i&&num[j]&&num[i-j]) ans += tri*num[j]%MOD*num[i-j]%MOD;
            ans %= MOD;
        }
    }
    cout<<ans<<endl;
    return 0;
}
