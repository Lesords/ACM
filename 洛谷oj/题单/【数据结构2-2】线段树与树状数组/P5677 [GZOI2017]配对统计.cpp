#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
#define lowbit(x) (x)&(-x)
using namespace std;

//题解：树状数组
//1. 首先先计算出所有满足条件的配对 (l,r)
//做法：先理解公式|ax-ay| <= |ax-ai|，其中  1 <= i <= n && i!=x
//由于有共同的x，所以可以理解为 指定一个x位置，找到另外一个y，使其相差的值最小
//又因为题目中不出现相同的数字，所以可将所有数字排序
//那么 好的配对 肯定是相邻的两个数（可能两个都满足）
//注意特判下左右端点的情况！！！
//2. 查询根据 右端点的位置 从小到大开始计算结果
//离线操作
//对于区间查询，我们可以先将所有 配对 排序一遍（根据右端点从小到大排序
//每次查询一个区间 [l, r] 时，将所有 右端点小于查询右区间 的配对放入树状数组中记录
//树状数组中记录的是每个 配对的左端点 ，因为这样的话可以满足
//当前所有配对的数量即为 [1, r] 的数量
//树状数组中 ask(l-1) 即为 [1, l-1] 的数量
//两者相减即为 当前区间查询的结果
//注意：记录左端点是因为当前所有点的右端点都满足区间条件，只有左端点有不满足条件的情况！！！

const int MAXN = 3e5+5;
struct node{
    int val,pos;
    friend bool operator < (node a,node b) {
        return a.val < b.val;//根据值排序
    }
}a[MAXN];//记录原数据
struct dot{
    int l, r;
    friend bool operator < (dot a, dot b) {
        //先根据右端点 从小到大 排序
        //再根据左端点 从小到大 排序
        if(a.r==b.r) return a.l < b.l;
        return a.r < b.r;
    }
}ans[MAXN*2];//记录 好的配对 信息
struct ques{
    int l, r, pos;
    friend bool operator < (ques a, ques b) {
        //先根据右端点 从小到大 排序
        //再根据左端点 从小到大 排序
        if(a.r==b.r) return a.l < b.l;
        return a.r < b.r;
    }
}op[MAXN];//记录对应的查询区间
int cnt, n, m;//cnt为 好的配对 的数量
int tree[MAXN];//树状数组，记录查询信息
void add_pair(int one,int two) {//添加配对
    int minn = min(a[one].pos, a[two].pos);//左位置
    int maxx = max(a[one].pos, a[two].pos);//右位置
    ans[++cnt] = {minn, maxx};
}
void add(int pos,int val) {//pos位置的值添加val
    while(pos<=n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
ll ask(int pos) {//查询 [1,pos] 的值
    ll ans = 0;
    while(pos) {
        ans += tree[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main() {
    cin>>n>>m;
    if(n==1) {//特判0的情况！！！
        cout<<"0\n";
        return 0;
    }
    for(int i = 1;i <= n;i++) {
        cin>>a[i].val;
        a[i].pos = i;//记录对应的位置
    }
    sort(a+1,a+1+n);//根据值排序
    add_pair(1,2);//特判左右端点
    add_pair(n-1, n);
    for(int i = 2;i < n;i++) {//记算中间部分的 配对
        int dif_l = abs(a[i].val-a[i-1].val);//与左边的差值
        int dif_r = abs(a[i].val-a[i+1].val);//与右边的差值
        if(dif_l==dif_r) {//相等则都取
            add_pair(i, i-1);
            add_pair(i, i+1);
        }//否则取较小值
        else if(dif_l<dif_r) add_pair(i, i-1);
        else add_pair(i, i+1);
    }
    sort(ans+1, ans+cnt+1);//根据右端点从小到大排序
    for(int i = 1;i <= m;i++) {//记录查询区间
        cin>>op[i].l>>op[i].r;
        op[i].pos = i;//查询的编号
    }
    sort(op+1, op+m+1);//根据右端点从小到大排序
    ll res = 0;//res为结果
    int pos = 1,cur = 0;//pos为当前的配对位置，cur为配对数量
    for(int i = 1;i <= m;i++) {//遍历所有查询
        int now_r = op[i].r;//当前查询区间的右端点
        //存在当前配对，并且配对的右端点不超过当前区间时，记录到树状数组中
        while(pos<=cnt&&ans[pos].r<=now_r) {
            add(ans[pos].l, 1);//记录到 配对 的右端点位置
            cur++;//数量++
            pos++;//配对位置后移
        }
        //cur-ask(op[i].l-1) 即为当前区间的 配对 数量
        res += op[i].pos*(cur-ask(op[i].l-1));
    }
    cout<<res;
    return 0;
}
