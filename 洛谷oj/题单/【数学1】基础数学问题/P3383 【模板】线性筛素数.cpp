#include<iostream>//ac
#include<algorithm>
using namespace std;

//��⣺����ɸ����Ҫע��prim����Ĵ�С��1e8��Χ�ڵ�������5761455������

const int MAXV = 1e8;
const int MAXN = 6e6+6;//5761455
int prim[MAXN],v[MAXV+10];//prim��¼������v��¼��ǰ������С������
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int cnt = 0;
    for(int i = 2;i <= MAXV;i++) {//MAXV������
        if(v[i]==0) {
            prim[++cnt] = i;
            v[i] = i;
        }
        for(int j = 1;j <= cnt;j++) {
            if(i*1ll*prim[j]>MAXV||v[i]<prim[j]) break;
            v[i*prim[j]] = prim[j];
        }
    }
    int n,q,tmp;
    cin>>n>>q;
    while(q--) {
        cin>>tmp;
        cout<<prim[tmp]<<"\n";
    }
    return 0;
}
