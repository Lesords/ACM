#include<iostream>//ac
#include<algorithm>
using namespace std;
const int MAXN = 1e4+5;
int a[MAXN];
int main() {
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i];
    //next_permutation����ֱ��������һ������
    while(m--) next_permutation(a+1,a+1+n);
    //�������������еĴ�С��+m������m�κ������
    for(int i = 1;i <= n;i++) cout<<a[i]<<' ';
    return 0;
}
