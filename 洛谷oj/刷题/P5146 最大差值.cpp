#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;
const int MAXN = 1e6+6;
int a[MAXN];
int main() {
    int n,minn = INF,ans = 0;//��Сֵ��ʼ��ΪINF�������ʼ��Ϊ0����Ϊ-INF��
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        minn = min(minn,a[i]);//��¼��Сֵ
        ans = max(ans,a[i]-minn);//ȡ ��ǰֵ-��Сֵ �Ľϴ�ֵ
    }
    cout<<ans<<endl;
    return 0;
}
