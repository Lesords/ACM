#include<iostream>//ac (���ִ�)
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e6+5;
int a[MAXN],n,m,maxx;
bool check(ll mid) {
    ll res = 0;
    for(int i = 1;i <= n;i++) {
        if(a[i]>=mid) res+=a[i]-mid;
    }//�жϿ��������Ƿ���������
    return res>=m;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        maxx = max(maxx,a[i]);//�������Ϊ������ֵ
    }
    ll l = 0,r = maxx,ans = 0;
    while(l<=r) {//����
        ll mid = (l+r)/2;
        if(check(mid)) ans = mid, l = ans+1; //����ans
        else r = mid-1;
    }
    cout<<ans<<endl;
    return 0;
}
