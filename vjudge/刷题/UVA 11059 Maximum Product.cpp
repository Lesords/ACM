#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;
ll a[20];
int main() {
    int n,cas = 1;
    while(cin>>n) {
        for(int i = 1;i <= n;i++) cin>>a[i];
        ll ans = 0;
        for(int i = 1;i <= n;i++) {//遍历所有起点
            ll tmp = 1;
            //遍历所有终点
            for(int j = i;j <= n;j++) tmp *= a[j],ans = max(ans,tmp);
            //乘的同时更新答案
        }//cas++！！！
        cout<<"Case #"<<cas++<<": The maximum product is "<<ans<<".\n\n";
    }
    return 0;
}
