#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//��⣺����n���������ӣ�������С�����ӣ���Ӧ������һ������С��k��

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k,ans = INF;
        cin>>n>>k;//kΪ������С
        for(int i = 1;i*i <= n;i++) {
            if(n%i==0) {//һ�μ����������
                if(n/i<=k) ans = min(ans,i);//i�� n/i ��С�İ�
                if(i<=k) ans = min(ans,n/i);//n/i�� i ��С�İ�
            }
        }
        cout<<ans<<"\n";//�����ٸ���
    }
    return 0;
}
