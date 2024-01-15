#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
int main() {
    int n,k;
    cin>>n>>k;
    for(int i = 1;i <= n;i++) cin>>a[i];
    sort(a+1,a+n+1);//从小达到排序
    if(k==0) {//特判0个数的时候
        if(a[1]==1) cout<<"-1\n";//第一个值为1（最低值），则无解
        else cout<<"1\n";//否则输出1即可
    }
    else if(k==n) cout<<a[k]<<"\n";//总共就k个，则直接输出即可
    else {
        if(a[k+1]==a[k]) cout<<"-1\n";//若k+1和k的位置相同，则无解
        else cout<<a[k]<<"\n";//否则直接输出k位置的值
    }
    return 0;
}
