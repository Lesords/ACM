// Problem: P3834 【模板】可持久化线段树 2
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P3834
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Author：Lese
// Time：2021-09-18 14:39:33

#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<sstream>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<bitset>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
#define eps 1e-6
using namespace std;
const int MAXN = 2e5+5;
const int MOD = 1e9+7;
const double pi = acos(double(-1));

//主席树模板
const int N = 200000 + 5;
struct Seg {
    int ls, rs;
    int sum;
}t[N*40];
int rt[N], tot;
vector<int> all;
int n, a[N], l, r, k, m;
int build(int l, int r) {
    int p = ++tot;
    if(l == r) {
        t[p].sum = 0;
        return p;
    }
    int mid = (l + r) >> 1;
    t[p].ls = build(l, mid);
    t[p].rs = build(mid+1, r);
    t[p].sum = 0;
    return p;
}
int insert(int now, int l, int r, int pos, int val) {
    int p = ++tot;
    t[p] = t[now];
    if(l == r){
        t[p].sum += val;
        return p;
    }
    int mid = (l + r) >> 1;
    if(pos <= mid) t[p].ls = insert(t[now].ls, l, mid, pos, val);
    else t[p].rs = insert(t[now].rs, mid+1, r, pos, val);
    t[p].sum = t[t[p].ls].sum + t[t[p].rs].sum;
    return p;
}
int ask(int p, int q, int l, int r, int k) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    int lcnt = t[t[q].ls].sum - t[t[p].ls].sum;
    if(k <= lcnt) return ask(t[p].ls, t[q].ls, l, mid, k);
    else return ask(t[p].rs, t[q].rs, mid+1, r, k - lcnt);
}
int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        all.push_back(a[i]);
    }
    sort(all.begin(), all.end());
    all.erase(unique(all.begin(), all.end()), all.end()); //离散化
    for(int i = 1;i <= n;i++) {
        a[i] = lower_bound(all.begin(), all.end(), a[i]) - all.begin() + 1;
    }
    rt[0] = build(1, all.size());//初始线段树
    for(int i = 1;i <= n;i++) {
        rt[i] = insert(rt[i-1], 1, all.size(), a[i], 1);
    }
    while(m--) {
        scanf("%d%d%d", &l, &r, &k);//[l, r] 区间内第k小值
        printf("%d\n", all[ask(rt[l-1], rt[r], 1, all.size(), k) - 1]);
    }
    return 0;
}
