#include<iostream>//ac
#include<algorithm>
#define lowbit(a) (a)&(-a)
using namespace std;

//��⣺��״����ģ����
//��ô����һ������val�൱���ڸ�λ�����val
//Ȼ������ǰ׺�Ͳ�ѯ����ֵ

const int MAXN = 5e5+5;
int a[MAXN],tree[MAXN];
int n,m;
void add(int pos,int val) {//��posλ�õ�ֵ����val
    while(pos<=n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
int ask(int pos) {//��ѯ[1,pos]��ֵ
    int ans = 0;
    while(pos>=1) {
        ans += tree[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) cin>>a[i],add(i,a[i]);
    while(m--) {
        int op,x,y;
        cin>>op>>x>>y;
        if(op==1) add(x,y);
        else cout<<ask(y)-ask(x-1)<<"\n";
    }
    return 0;
}
