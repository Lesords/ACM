#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺���串�����⣬���������յ����򣬽������Ӱ�죡����
//�������Ϊ�Ѷ�����ķ�Χ�Ƶ�����ȥ
//Ȼ�����ж��߶��Ƿ��ظ���ɾ���ظ����ּ���

const int MAXN = 2e4+5;
int a[MAXN],b[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i]>>b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);//����
    ll ans = 0;//���ظ���ʱ����ܻᱬint
    for(int i = 1;i <= n;i++) {
        ans += b[i]-a[i];//�����
        //��ǰ�������һ��ʱ���ж�����һ���Ƿ����ظ���ɾ���ظ�����
        if(i+1<=n&&a[i+1]<b[i]) ans -= b[i]-a[i+1];
    }
    cout<<ans;
    return 0;
}
