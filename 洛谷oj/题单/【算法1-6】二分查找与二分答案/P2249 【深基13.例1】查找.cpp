#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺ֱ�Ӷ��ֲ��ң�����һ����ֵ����

const int MAXN = 1e6+6;
int a[MAXN];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    for(int i = 1;i <= m;i++) {
        int tmp;
        cin>>tmp;
        int pos = lower_bound(a+1,a+1+n,tmp)-a;
        if(a[pos]!=tmp) cout<<"-1 ";//��Ϊtmp��Ϊ-1
        else cout<<pos<<" ";
    }
    return 0;
}
