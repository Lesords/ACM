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
#define INF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺�������е� ai ��С��n
//��ô���� ai|aj ���ԣ����ֵΪ 2*n����СֵΪ0
//���� i*j ��˵�����ֵΪ (n-1) * n
//����ڣ�n-1,n)��˵��
//���ֵ����� (n-1)*n - k*0 = (n-1)*n
//��Сֵ����� (n-1)*n - k*(2n)
//��������λ�� (i,n) ���ԣ�Ҫ��ֵ���� (n-1,n)
//��ô���� ai|aj = 0����Ϊ i*n
//�����iλ�ô��� n-1 λ�õĿ���Ϊ��i������n-1����С��
// i*n > (n-1)*n - k*(2n)
// i > (n-1) - 2*k
//�� i >= n - 2k
//Ҳ����˵������ֻ��Ҫ�� n-2k λ�ÿ�ʼ��������
//ע�� n-2k ��Ϊ��������Ҫ��Ϊ1������


const int MAXN = 2e5+5;
const int MOD = 1e9+7;
ll a[MAXN];
int main() {
    fast;
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        for(int i = 1;i <= n;i++) {
            cin>>a[i];
        }
        ll ans = -INF;
        int l = max(1, n-2*k);//λ�ò���Ϊ����������
        for(int i = n;i >= l;i--) {
            for(int j = l;j < i;j++) {//��l��ʼ��������
                ans = max(ans, i*1ll*j-k*1ll*(a[i]|a[j]));
            }
        }
        cout<<ans<<"\n";
    }
	return 0;
}
