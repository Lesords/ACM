#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：若有两种类型数值则肯定可以有序
//否则需要判断是否已经有序

const int MAXN = 505;
int a[MAXN],b[MAXN];
int main() {
    int t;cin>>t;
    while(t--) {
        int n,one = 0,zero = 0;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        for(int i = 1;i <= n;i++) {
            cin>>b[i];
            b[i]?one++:zero++;//统计对应类型的数量
        }
        if(is_sorted(a+1,a+1+n)) {//已经有序则有解
            cout<<"Yes\n";
            continue;
        }
        if(one>=1&&zero>=1) cout<<"Yes\n";//否则两个类型都有才能有解
        else cout<<"No\n";
    }
    return 0;
}
