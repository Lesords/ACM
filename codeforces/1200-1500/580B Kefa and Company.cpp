#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����Ǯ�Ĵ�С������������˫ָ�����ǮΪd��Χ�ڵ��������غ�
//������ǰ׺�������������������غ�

const int MAXN = 1e5+5;
struct node{
    ll money, fact;
    friend bool operator < (node a,node b) {
        return a.money < b.money;
    }
}a[MAXN];
ll sum[MAXN];
int main() {
    ll n,d;
    cin>>n>>d;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].money>>a[i].fact;
    }
    sort(a+1,a+n+1);//����
    for(int i = 1;i <= n;i++) sum[i] = sum[i-1] + a[i].fact;//ǰ׺��
    ll ans = 0;
    ll l = 1,r = 1;
    while(r<=n) {//rΪĩβ����
        if(a[r].money-a[l].money<d)//��d�ķ�Χ��ʱ��������d��������
            while(r+1<=n&&(a[r+1].money-a[l].money)<d) r++;//��һ��Ҳ����d
        else while(a[r].money-a[l].money>=d) l++;//��ǰ�����㣬��l����
        ans = max(ans, sum[r]-sum[l-1]);//ȡ [l,r] ����͵Ľϴ�ֵ
        r++;//�ƶ�r���������㣨��Ϊ��ʱ[l,r]һ������������
    }
    cout<<ans;
    return 0;
}
