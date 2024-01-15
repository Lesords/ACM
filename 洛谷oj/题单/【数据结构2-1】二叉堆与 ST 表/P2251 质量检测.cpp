#include<iostream>//ac
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 1e6+6;
int a[MAXN],f[MAXN][25];
int n,m;
void ST_init() {
    memset(f,0x3f,sizeof(f));//��ʼ��Ϊ���ֵ
    for(int i = 1;i <= n;i++) f[i][0] = a[i];//�߽�ֵ
    int siz = log(n)/log(2);//��������
    for(int i = 1;i <= siz;i++) {
        for(int j = 1;j+(1<<i)-1 <= n;j++) {
            int len = 1<<(i-1);
            //ע��j��i��˳�򣡣���
            //j����㣬i�����䳤��
            f[j][i] = min(f[j][i-1],f[j+len][i-1]);
        }
    }
}
int query(int l,int r) {
    int siz = log(r-l+1)/log(2);
    return min(f[l][siz],f[r-(1<<siz)+1][siz]);
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    ST_init();
    for(int i = 1;i <= n-m+1;i++) {//���(n-m+1)�����䳤��Ϊm����Сֵ����
        cout<<query(i,i+m-1)<<"\n";
    }
    return 0;
}
