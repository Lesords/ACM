#include<iostream>//ac
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//��⣺����map��pairǶ�����
//pair��Ϊλ�ã�map�洢��Ӧλ�õ�ֵ

const int MAXN = 1e5+5;
map<pii,int> sto;
int main() {
    int n,q;
    cin>>n>>q;
    for(int i = 1;i <= q;i++) {
        int op,x,y,k;
        cin>>op;
        if(op==1) {
            cin>>x>>y>>k;
            sto[{x,y}] = k;//ֱ�Ӵ�ֵ
        }
        else {
            cin>>x>>y;
            cout<<sto[{x,y}]<<"\n";//ֱ��ȡֵ
        }
    }
    return 0;
}
