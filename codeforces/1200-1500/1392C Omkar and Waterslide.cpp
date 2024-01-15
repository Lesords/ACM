#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：可以将非升序块不断分块，然后从内到外开始增加，这样每处只添加一次
//这样结果就相当于只添加 前一个数-当前数 的值

const int MAXN = 2e5+5;
int a[MAXN];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i = 1;i <= n;i++) cin>>a[i];
        ll ans = 0;
        for(int i = 2;i <= n;i++) {
            //前一个数大于当前数时
            if(a[i-1]>a[i]) ans += a[i-1]-a[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
