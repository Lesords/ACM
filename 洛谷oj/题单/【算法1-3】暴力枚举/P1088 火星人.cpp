#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    //next_permutation可以直接生成下一个序列
    while(m--) next_permutation(a+1,a+1+n);
    //火星数即该排列的大小，+m即操作m次后的序列
    for(int i = 1;i <= n;i++) cout<<a[i]<<' ';
    return 0;
}
