#include<iostream>//ac
#include<algorithm>
using namespace std;

//题解：树状数组
//由于对于给定的区间来说，如果一个数多次出现，那么只取最后一次出现的位置即可
//也就是说，对于重复的数字来说，只有最后出现的次数才有贡献
//那么我们可以离线操作
//将所有查询序列按照右区间从小到大排序
//利用树状数组来维护每个数字出现贡献的位置（当前位置有贡献，则为1）
//利用last数组记录对应数字出现的最后一个的位置
//然后每次将当前查询右区间前面的数字，更新到树状数组中去
//记得删除 重复的数字 的贡献

const int MAXN = 1e6+6;
struct node{
    int l,r,id;//id为查询的编号
    friend bool operator < (node a,node b) {
        //先右区间从小到大，再左区间从小到大
        if(a.r==b.r) return a.l < a.l;
        return a.r < b.r;
    }
}que[MAXN];//记录查询
int a[MAXN], last[MAXN], ans[MAXN], tree[MAXN];
//last记录最后的位置，ans为最后结果，tree为树状数组
int n,m;

inline char gch()
{
    static char buf[100010], *h = buf, *t = buf;
    return h == t && (t = (h = buf) + fread(buf, 1, 100000, stdin), h == t) ? EOF : *h ++;
}
template<class T>
inline void re(T &x)
{
    x = 0;
    char a; bool b = 0;
    while(!isdigit(a = gch()))
        b = a == '-';
    while(isdigit(a))
        x = (x << 1) + (x << 3) + a - '0', a = gch();
    if(b == 1)
        x *= -1;
}

int lowbit(int x) { return (x)&(-x); }
void add(int pos, int val) {//pos位置添加val
    while(pos<=n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
int ask(int pos) {//查询pos的前缀和
    int ans = 0;
    while(pos) {
        ans += tree[pos];
        pos -= lowbit(pos);
    }
    return ans;
}
int main() {
    re(n);
    for(int i = 1;i <= n;i++) {
        re(a[i]);
    }
    re(m);
    for(int i = 1;i <= m;i++) {
        re(que[i].l),re(que[i].r);
        que[i].id = i;
    }
    sort(que+1, que+m+1);//排序查询
    int pos = 0;//当前操作的原数组位置
    for(int i = 1;i <= m;i++) {
        while(pos+1<=que[i].r) {//如果下一个位置在查询范围内
            pos++;//移到下一个位置，下一个位置才是操作位置！！！
            int lst = last[a[pos]];//记录当前字符上一次出现的位置
            if(lst) add(lst, -1);//出现过，则删除对应的贡献
            add(pos, 1);//添加当前位置的贡献
            last[a[pos]] = pos;//更新对应位置
        }
        int id = que[i].id;
        ans[id] = ask(que[i].r)-ask(que[i].l-1);//前缀和差即为区间值
    }
    for(int i = 1;i <= m;i++) cout<<ans[i]<<"\n";
    return 0;
}
