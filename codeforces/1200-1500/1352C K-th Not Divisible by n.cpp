#include<iostream>//ac
#include<algorithm>
#define ll long long
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;

//��⣺���ֽ��⣬����0-INFΪ���ֵķ�Χ
//Ȼ�����ÿ��mid��λ���Ƿ�����k
//����mid��λ��Ϊ mid - mid/n����
//��Ҫ����midΪn�ı���ʱ�������ֵ��-1������

ll n,k;
ll cal(ll val) {//����val��λ��
    return val-val/n;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>k;
        ll l = 0,r = INF;//���ַ�ΧΪ0-INF
        while(l<=r) {
            ll mid = (l+r)>>1;
            if(cal(mid)==k) {//λ����������ʱ
                if(mid%n==0) cout<<mid-1<<"\n";//���п������������������
                else cout<<mid<<"\n";
                break;
            }
            else if(cal(mid)>k) r = mid-1;//λ�ô���������
            else l = mid+1;//С������
        }
    }
    return 0;
}
