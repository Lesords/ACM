#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define fi first
#define se second
using namespace std;

//��⣺������Ŀ��Ҫ����λ�� ǰ������ �� ������� ���
//��ô���Ľ���϶�Ϊ ������������ ������
//����ֻ��Ҫ���� ������������ ������num�����������β���ˣ�Ȼ���м��������򼴿�
//�����Ϊ�� (num*(num-1)*(n-2)!)%MOD   numѡ������������*ʣ������ȫ����
//ע�⣺������ֻ��������ʱ���м�ֵӦ��Ϊ1������0������

const int MAXN = 2e5+5;
const ll MOD = 1e9+7;
ll a[MAXN],sum[MAXN];//����sumԤ����׳˵Ļ������ʼ��sum[0] = sum[1] = 1������
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,num = 0;
        cin>>n;
        ll ans;//�������յ� ����
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
            if(i==1) ans = a[i];
            else ans &= a[i];
        }
        for(int i = 1;i <= n;i++) {
            if(a[i]==ans) num++;//ͳ�� ���� ���ֵĴ���
        }
        ll siz = (num*(num-1ll))%MOD;//�ȼ������˵�ֵ
        for(int i = 1;i <= n-2;i++) {//Ȼ���ټ���׳ˣ��м䲿�֣�
            siz = (siz*i)%MOD;
        }
        cout<<siz<<"\n";
    }
	return 0;
}
