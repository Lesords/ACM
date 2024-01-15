#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;
const int MAXN = 1e5+5;
int a[MAXN],f[MAXN][20];
int n,m;
void RMQ_init() {
    for(int i = 1;i <= n;i++) f[i][0] = a[i];//�߽�
    int siz = log(n)/log(2);//sizֻ���ڼ��㱶����ģ������
    for(int i = 1;i <= siz;i++) {
        //jΪ��㣬 j+(1<<i)-1Ϊ�յ�
        //i������ֳ�����(i-1)С����
        for(int j = 1;j+(1<<i)-1 <= n;j++) {
            int len = 1<<(i-1);//������ֳ�����С����
            f[j][i] = max(f[j][i-1], f[j+len][i-1]);
        }
    }
}
int query(int l,int r) {// ��[l,r]�������ֵ
    int siz = log(r-l+1)/log(2);
    return max(f[l][siz],f[r-(1<<siz)+1][siz]);
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    RMQ_init();
    while(m--) {
        int l,r;
        cin>>l>>r;
        cout<<query(l,r)<<"\n";
    }
    return 0;
}
