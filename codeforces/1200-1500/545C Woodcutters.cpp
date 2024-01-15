#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：贪心：能向左倒就向左倒，能像右倒就向右倒，否则不动

const int MAXN = 1e5+5;
int a[MAXN], h[MAXN];
int main() {
    int n,ans = 0;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i]>>h[i];
    }
    for(int i = 1;i <= n;i++) {
        if(i==1) ans++;//第一个位置
        else {
            if(a[i]-h[i]>a[i-1]) ans++;//可以向左倒
            else if(i==n||a[i]+h[i]<a[i+1]) {//最后一个或者可以向右倒
                ans++;
                a[i] += h[i];//向右倒需要更新当前树的位置！！！
            }
        }
    }
    cout<<ans;
    return 0;
}
