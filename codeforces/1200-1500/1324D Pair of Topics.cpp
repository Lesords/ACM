#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺a[i]+a[j] > b[i]+b[j] ��ת��Ϊ a[i]-b[i] > -(a[j]-b[j])
//���Կ��Լ���a[i]-b[i]��ֵ��Ȼ��Ӻ���ǰ���ö��ּ�������������λ��

const int MAXN = 2e5+5;
ll a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 1;i <= n;i++) {
        ll tmp;
        cin>>tmp;
        a[i] -= tmp;//��������Ľ��
    }
    sort(a+1,a+n+1);//����
    ll ans = 0;//����ᱬint
    for(ll i = n;i >= 1;i--) {//�Ӻ���ǰ���ң������ֵ��
        if(a[i]<=0) break;//С��0����ֱ�ӽ�����ǰ��ĸ�С��
        ll pos = upper_bound(a+1,a+i,-a[i])-a;//�ҵ���һ������ -a[i]��λ��
        ans += i-pos;// [pos,i)������������������������-a[i]
    }
    cout<<ans<<"\n";
    return 0;
}
