#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺����Ŀת��Ϊ��aliceѡż���ӷ֣�bobѡ�����۷�
//��ô�ܷ�Ϊ0��Ϊƽ�֣�����0��aliceӮ��С��0��bobӮ
//��ô���ŵķ������Ӵ�С����ÿ��ѡ�����ֵ���Լ����ӷֶ����öԷ��ӷ֣�

const int MAXN = 2e5+5;
int a[MAXN];
bool cmp(int a,int b) {
    return a > b;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        sort(a+1,a+1+n,cmp);//�Ӵ�С����
        ll ans = 0;
        for(int i = 1;i <= n;i++) {
            if(i%2) {//������Ϊalice�Ļغ�
                if(a[i]%2==0) ans += a[i];//ż���ӷ�
            }
            else {//����Ϊbob�Ļغ�
                if(a[i]%2) ans -= a[i];//�����۷�
            }
        }
        if(ans==0) cout<<"Tie\n";
        else if(ans>0) cout<<"Alice\n";
        else cout<<"Bob\n";
    }
    return 0;
}
