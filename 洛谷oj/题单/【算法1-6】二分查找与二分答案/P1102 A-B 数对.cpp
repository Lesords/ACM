#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN],n,c;
int main() {
    ll ans = 0;//����32λ�������int
    cin>>n>>c;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+n+1);//��С��������
    for(int i = 1;i < n;i++) {
        //�������������������������Ե���������
        int l = lower_bound(a+i+1,a+n+1,c+a[i])-a;//��һ�����ڵ��� x
        int r = upper_bound(a+i+1,a+n+1,c+a[i])-a;//��һ������ x
        ans += r-l;//�����Ϊ��ƥ����
    }
    cout<<ans<<endl;
    return 0;
}
