#include<iostream>//ac
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
const int MAXN = 2e5+5;

//题意：共有n个猫，共有两个操作：
//1. 将两个猫堆合并
//2. 查询数量第k大的猫堆 数量
//题解：并查集+树状数组
//每次合并的时候利用并查集来判断对应的堆，然后将其合并，更新对应数量
//初始化对应堆的数量为1
//由于需要查询第k大，那么可以用树状数组来维护每种数量出现的次数（权值树状数组）
//初始化时，树状数组中 1 的值为n！！！
//每次合并的时候，将树状数组中 对应数量 的值-1
//将树状数组中 对应数量和 的值 +1（两个小堆合并起来）
//由于树状数组是求第 k 小的值，那么可以将第k大转换为对应的第 n-k+1 小(n为总数)
//并查集合并的时候，顺便记录堆的数量

int tree[MAXN],dis[MAXN],num[MAXN];//tree树状数组维护对应值出现的次数
//dis记录祖先，num记录对应祖先堆的数量
int n, m, cnt;//cnt为当前堆的数量

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
int getf(int pos) {//寻找pos的祖先
    return pos==dis[pos]?pos:dis[pos]=getf(dis[pos]);
}
void add(int pos, int val) {//pos位置添加val
    while(pos<=n) {
        tree[pos] += val;
        pos += lowbit(pos);
    }
}
int kth(int rk) {//求第rk大
    int siz = log2(n);//最大的幂
    int num = 0,pos = 0;//num为当前统计数量，pos为当前计算的位置
    rk = cnt-rk+1;//转换为第 cnt-rk+1 小
    for(int i = siz;~i;i--) {//计算到-1时结束
        pos += 1<<i;//累加位置
        //位置不能大于等于n，并且数量不能大于等于rk
        //也就是说到达一个边界，使得当前位置都不满足，那么下面一个位置一定是满足条件的
        if(pos>=n||num + tree[pos]>=rk) {
            pos -= 1<<i;
        }
        else num += tree[pos];//满足条件，累加数量
    }
    return pos+1;//下一个位置即为结果
}
int main() {
    re(n), re(m);
    cnt = n;//初始化堆的数量即为n
    //初始化祖先为本身，对应数量为1
    for(int i = 1;i <= n;i++) dis[i] = i,num[i] = 1;
    add(1, n);//树状数组中1的数量为n
    for(int cas = 1;cas <= m;cas++) {
        int op,x,y;
        re(op), re(x);
        if(op==0) {
            re(y);
            x = getf(x);
            y = getf(y);
            if(x==y) continue;//为同一堆，无需合并
            cnt--;//合并之后，就会少一个堆
            add(num[x], -1);//两个堆数量对应的值减少
            add(num[y], -1);
            add(num[x]+num[y], 1);//堆数量总和对应的值增加（合并
            //向左合并！！！
            dis[y] = x;//y的祖先为x
            num[x] += num[y];//那么x的数量就要增加
        }
        else printf("%d\n", kth(x));
    }
    return 0;
}
