#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//��⣺�����ξ����ֳ������Σ����в������������ݹ����
//�ɻ�ͼ���

ll solve(ll a,ll b) {
    if(a<b) swap(a,b);//��aΪ��bΪ��
    ll ans = 0;
    ans += b*4*(a/b);//���Էֳ� (a/b) ����Ϊb��������(�ܳ�Ϊ4b)
    if(a%b) ans += solve(b,a%b);//���ж��ಿ�֣��ݹ���㣨bΪ����a%bΪ��
    return ans;
}
int main() {
    ll a,b;
    cin>>a>>b;
    cout<<solve(a,b);
    return 0;
}
