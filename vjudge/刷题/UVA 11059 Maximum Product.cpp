#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
ll a[20];
int main() {
    int n,cas = 1;
    while(cin>>n) {
        for(int i = 1;i <= n;i++) cin>>a[i];
        ll ans = 0;
        for(int i = 1;i <= n;i++) {//�����������
            ll tmp = 1;
            //���������յ�
            for(int j = i;j <= n;j++) tmp *= a[j],ans = max(ans,tmp);
            //�˵�ͬʱ���´�
        }//cas++������
        cout<<"Case #"<<cas++<<": The maximum product is "<<ans<<".\n\n";
    }
    return 0;
}
