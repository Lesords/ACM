#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 1e6+5;

//��⣺���� \sum_{d|n} phi(d) = n
//�� n = gcd(i,j)��Ȼ�����
//����Χ��Ȼ��������������������
//�ɽ������Ϊ phi[i] * n/i * n/i  ���У� 1<=i<=n

int v[MAXN], prim[MAXN], phi[MAXN], cnt;
void euler(int n) {
    phi[1] = 1;//1ֱ�Ӽ���
    for(int i = 2;i <= n;i++) {
        if(v[i]==0) {
            v[i] = i, prim[++cnt] = i;
            phi[i] = i-1;
        }
        for(int j = 1;j <= cnt;j++) {
            if(v[i]<prim[j] || prim[j]>n/i) break;
            v[i*prim[j]] = prim[j];
            phi[i*prim[j]] = phi[i]*( i%prim[j] ?prim[j]-1:prim[j]);
        }
    }
}
int main() {
    int n;
    cin>>n;
    euler(n);
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        ans += phi[i]*(n/i)*1ll*(n/i);
    }
    cout<<ans<<"\n";
    return 0;
}
