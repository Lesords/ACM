#include<iostream>//ac
#include<algorithm>
#define lowbit(x) (x)&(-x)
using namespace std;

//题解：树状数组上维护差分
//由于树状数组支持单点修改和区间查询
//其中区间查询是 利用前缀和 的思想
//那么对于区间操作，我们可以利用差分思想
//例：[x,y]区间内加val，则有add(x,val), add(y+1,-val)
//那么到时候对pos查询的值即为pos本身的原来值
//因为对差分进行前缀和的结果即为原来数字值

const int MAXN = 500005;
int n,m,tree[MAXN];
void add(int pos,int val) {//对pos增加val
    while(pos<=n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
int ask(int pos) {//查询pos位置的值
    int ans = 0;
    while(pos>=1) {
        ans += tree[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main() {
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        int tmp;
        cin>>tmp;
        add(i,tmp);//[i,i]区间增加tmp
        add(i+1,-tmp);
    }
    while(m--) {
        int op,x,y,k;
        cin>>op;
        if(op==1) {
            cin>>x>>y>>k;
            //差分操作
            add(x,k),add(y+1,-k);
        }
        else {
            cin>>x;
            cout<<ask(x)<<"\n";
        }
    }
    return 0;
}
