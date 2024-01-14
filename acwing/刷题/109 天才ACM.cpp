#include<iostream>//ac
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int MAXN = 5e5+6;

//题解：倍增求范围，然后判定是否满足条件，利用归并排序思想来简化区间排序

int n,m,last;
ll a[MAXN],b[MAXN],c[MAXN],k;//k是longlong类型！！！
void Merge(int l,int mid,int r) {//合并区间[l,mid] [mid+1,r]
    int i = l,j = mid+1;
    for(int k = l;k <= r;k++) {
        if(j>r||(i<=mid&&b[i]<=b[j])) c[k] = b[i++];
        else c[k] = b[j++];
    }
}
ll solve(int l,int r) {//计算l-r区间的最大校验值
    if(r>n) r = n;//最多只能到n
    int siz = min(m,(r-l+1)>>1);//计算可以取多少对，不能超过要求m
    for(int i = last+1;i <= r;i++) b[i] = a[i];//多出来的部分
    sort(b+last+1,b+r+1);//将多出的部分排序
    Merge(l,last,r);//然后将两块合并
    ll ans = 0;//计算校验值
    for(int i = 0;i < siz;i++) {//c数组为合并后的结果（有序
        ans += (c[r-i]-c[l+i])*(c[r-i]-c[l+i]);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        for(int i = 1;i <= n;i++) cin>>a[i];
        int l = 1,r = 0,cnt = 0;//l为当前段起点，r为上一个段的终点，cnt为段数
        last = 0;//初始为空
        while(l<=n) {
            int p = 1;
            while(p) {//倍增，直到p为0
                ll num = solve(l, r+p);//计算 [l,r+p] 区间的校验值
                if(num<=k) {
                    last = r = min(n,r+p);//更新last为r的值
                    if(r==n) break;//如果到达终点，则结束
                    for(int i = l;i <= r;i++) b[i] = c[i];//更新数组（排序后的数组）
                    p <<= 1;
                }
                else p >>= 1;
            }
            cnt++;
            l = r+1;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}
