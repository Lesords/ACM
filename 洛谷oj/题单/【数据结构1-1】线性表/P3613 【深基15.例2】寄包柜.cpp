#include<iostream>//ac
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：利用map和pair嵌套求解
//pair作为位置，map存储对应位置的值

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
            sto[{x,y}] = k;//直接存值
        }
        else {
            cin>>x>>y;
            cout<<sto[{x,y}]<<"\n";//直接取值
        }
    }
    return 0;
}
