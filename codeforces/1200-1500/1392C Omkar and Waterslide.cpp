#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺���Խ�������鲻�Ϸֿ飬Ȼ����ڵ��⿪ʼ���ӣ�����ÿ��ֻ���һ��
//����������൱��ֻ��� ǰһ����-��ǰ�� ��ֵ

const int MAXN = 2e5+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        ll ans = 0;
        for(int i = 2;i <= n;i++) {
            //ǰһ�������ڵ�ǰ��ʱ
            if(a[i-1]>a[i]) ans += a[i-1]-a[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
