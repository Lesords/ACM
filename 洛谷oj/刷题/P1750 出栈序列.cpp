#include<iostream>//ac
#include<deque>
#include<algorithm>
#define ll long long
#define INF 0x7fffffff7fffffff
using namespace std;

//题解：设定两根指针l和r，l一开始为1，r一开始为c
//每次从l到r找到没被选中过的数中最小的一个打出，并设其为已选中
//l移至它前一个未被选中的数，r加一（如果r已经移至序列末尾，则不加一）。
//栈的原因，所以l只能为前一个未选中的数！！！
//l可以直接for遍历来寻找

const int MAXN = 1e4+5;
ll a[MAXN],in[MAXN];//in用来保存当前位置是否选择过
int main() {
    ll n,c;
    cin>>n>>c;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    ll l = 1,r = c,cnt = 0;//cnt记录输出的数量
    while(cnt<n) {//还未全部输出
        ll minn = INF, pos = 0;
        for(int i = l;i <= r;i++) {
            if(in[i]) continue;//跳过已选过的
            if(a[i]<minn) {//更新较小值
                minn = a[i];
                pos = i;
            }
        }
        in[pos] = 1;//标记选中
        cout<<a[pos]<<" ";
        cnt++;//更新数量
        for(int i = 1;i < pos;i++) {//寻找pos前第一个未选中的位置
            if(in[i]) continue;//跳过已选过的
            l = i;//不断更新，最后一个 即为 前第一个
        }
        if(r<n) r++;//r不到末尾才需要更新
    }
    return 0;
}
