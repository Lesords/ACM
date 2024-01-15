#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
#define lowbit(x) (x)&(-x)
using namespace std;

//题解：根据听力值，从小到大排序
//然后利用树状数组来存储对应位置的数量和值
//根据听力大小选择奶牛，那么对于每个新放入一个听力为val的奶牛now来说
//左边奶牛的音量为：(now - left1 + now - left2 + ···)*val
//右边奶牛的音量为：(rigt1 - now + right2 - now + ···)*val
//总和为：val*(now*左边奶牛数量 - 左边奶牛位置和 + 右边奶牛位置和 - now*右边奶牛数量)
//其中奶牛的 位置和 以及 数量和 可以用树状数组来维护
//树状数组的大小即为坐标的大小，树状数组根据奶牛对应的位置来维护数据


const int MAXN = 2e4+5;
const int MAXR = 2e4;
struct node{
    int v,x;
    friend bool operator < (node a,node b) {
        //先根据听力从小到大排序，再根据位置从小到大排序
        if(a.v!=b.v) return a.v < b.v;
        return a.x < b.x;
    }
}a[MAXN];
int num[MAXN],sum[MAXN];//num记录数量，sum计算总和
void add_num(int pos) {//pos位置的数量+1
    for(;pos<=MAXR;pos += lowbit(pos)) num[pos] += 1;
}
void add_val(int pos) {//pos位置的值+pos
    int val = pos;//值先赋值，因为pos的值会变！！！
    for(;pos<=MAXR;pos += lowbit(pos)) sum[pos] += val;
}
ll ask_num(int pos) {//求pos前的数量总和
    ll sum = 0;
    for(;pos;pos -= lowbit(pos)) sum += num[pos];
    return sum;
}
ll ask_sum(int pos) {//求pos前的听力总和
    ll ans = 0;
    for(;pos;pos -= lowbit(pos)) ans += sum[pos];
    return ans;
}
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        int v,x;
        cin>>v>>x;
        a[i] = {v,x};
    }
    sort(a+1,a+1+n);//排序
    ll ans = 0;
    for(int i = 1;i <= n;i++) {//逐个放入奶牛，并计算对应听力和
        ll lnum = ask_num(a[i].x);//左边的数量
        ll rnum = i-lnum-1;//总数-左边数量-当前一个
        ll lsum = ask_sum(a[i].x);//左区间总和
        ll rsum = ask_sum(MAXR)-lsum;//右区间总和 = 总和 - 左区间总和
        ans += a[i].v*(a[i].x*lnum-lsum+rsum-a[i].x*rnum);
        add_num(a[i].x);//a[i].x位置的数量+1
        add_val(a[i].x);//a[i].x位置的听力+a[i].x
    }
    cout<<ans;
    return 0;
}
