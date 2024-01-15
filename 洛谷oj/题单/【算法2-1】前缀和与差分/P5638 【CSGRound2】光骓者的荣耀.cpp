#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：求个1-n的前缀和
//由于只能跳一次，所以只需要求一段最大的k长区间和即可
//然后用 前缀和 - 区间和 即为结果

const int MAXN = 1e6+5;
ll pre[MAXN],a[MAXN];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 2;i <= n;i++) cin>>a[i],pre[i] = pre[i-1]+a[i];
    if(1+k>=n) {//一步直接跳到终点
        cout<<"0\n";return 0;
    }
    ll maxx = 0;//第一个点初始化为0
    for(int i = 1;i + k <= n;i++) {
        maxx = max(maxx,pre[i+k]-pre[i]);//k长区间
    }
    cout<<pre[n]-maxx<<endl;
    return 0;
}
