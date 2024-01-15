#include<iostream>//ac
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：线段树+分类讨论
//可以将题目转换成如下形式：
//给定a和b，判断 (a,b) 内的值是否都小于b的值，并且a大于等于b
//根据下标建线段树，用于查询对应区间的最大值
//然后需要判断给定的两个日期是否存在
//1. 如果b不存在
//判断a存在不存在，若a存在，则a需要大于 (a,b) 区间的值，否则为false
//如果a不存在，那么为maybe
//2. 如果a不存在
//由于b不存在已经排除了，所以此时b是存在的！！！
//那么如果a和b相差为1，或者a和b中间没有其他记录的年份，则为maybe
//如果 (a,b) 区间的值大于等于b，则为false
//否则为maybe
//3. 此时a和b都为存在
//直接判断 (a,b) 区间内的值是否小于b，并且a的值要大于等于b
//只有有一个不满足，即为false
//然后就需要判断 a和b 之间是否有年份未记录，如果有，则为maybe
//否则为true

const int MAXN = 5e4+5;
struct node{
    int l, r, maxx;//maxx记录对应区间的最大值
}tree[MAXN<<2];
int year[MAXN],rain[MAXN];//year为年份，rain为降雨量
//当前节点为rt，[l,r]为操作区间
void build(int rt, int l,int r) {
    tree[rt] = {l, r, -INF};
    if(l==r) {
        tree[rt].maxx = rain[l];
        return ;
    }
    int mid = (l+r)/2;
    build(rt*2, l, mid);
    build(rt*2+1, mid+1, r);
    tree[rt].maxx = max(tree[rt*2].maxx, tree[rt*2+1].maxx);
}
//rt为当前节点，[l,r]为查询区间
int query(int rt,int l,int r) {
    int L = tree[rt].l;//当前节点区间
    int R = tree[rt].r;
    //若包括，则直接返回区间最大值
    if(l<=L&&R<=r) return tree[rt].maxx;
    int mid = (L+R)/2;
    int ans = -INF;//初始化为-INF
    //分别计算左右子树的值
    if(l<=mid) ans = max(ans, query(rt*2, l, r));
    if(r>mid) ans = max(ans, query(rt*2+1, l, r));
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,m;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>year[i]>>rain[i];
    build(1, 1, n);
    cin>>m;
    while(m--) {
        int a,b;
        cin>>a>>b;//从a年开始，b值最大
        if(a>b) {
            cout<<"false\n";continue;
        }
        int pos_a = lower_bound(year+1, year+1+n, a)-year;
        int pos_b = lower_bound(year+1, year+1+n, b)-year;
        int is_a = a==year[pos_a]&&(pos_a<=n);//判断a是否存在
        int is_b = b==year[pos_b]&&(pos_b<=n);//判断b是否存在
        //如果b不存在
        if(!is_b) {
            //a位置不能小于b位置！！！
            if(is_a) {
                int maxx = query(1, pos_a+1, pos_b-1);
                //中间部分肯定要小于b位置，所以a位置不能小于等于中间位置！！！
                if(rain[pos_a]<=maxx) {
                    cout<<"false\n";continue;
                }
            }
            cout<<"maybe\n";continue;
        }
        //如果a不存在（此时b存在
        if(!is_a) {
            if(a+1==b||pos_a==pos_b) {
                cout<<"maybe\n";continue;
            }
            int maxx = query(1, pos_a, pos_b-1);
            if(maxx>=rain[pos_b]) {//中间值大于b的值，为false
                cout<<"false\n";continue;
            }
            cout<<"maybe\n";continue;
        }
        //此时a和b都存在
        int maxx = query(1, pos_a+1, pos_b-1);//计算中间的值
        //中间值不能大于等于b的值，a的值不能小于b的值
        if(maxx>=rain[pos_b]||rain[pos_a]<rain[pos_b]) {
            cout<<"false\n";continue;
        }
        //所以年份都记录，即为true
        if(b-a==pos_b-pos_a) cout<<"true\n";
        else cout<<"maybe\n";
    }
    return 0;
}
