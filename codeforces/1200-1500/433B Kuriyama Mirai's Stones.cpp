#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：原数组前缀和+有序数组前缀和

const int MAXN = 1e5+5;
ll a[MAXN],b[MAXN],sumA[MAXN],sumB[MAXN];
int main() {
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i],b[i] = a[i];
    sort(b+1,b+1+n);//排序
    for(int i = 1;i <= n;i++) {//前缀和
        sumA[i] = sumA[i-1] + a[i];
        sumB[i] = sumB[i-1] + b[i];
    }
    cin>>m;
    for(int i = 1;i <= m;i++) {
        int op,l,r;
        cin>>op>>l>>r;
        //op判断是哪个操作！！！
        if(op==1) cout<<sumA[r]-sumA[l-1]<<"\n";
        else cout<<sumB[r]-sumB[l-1]<<"\n";
    }
    return 0;
}
