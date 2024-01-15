#include<iostream>//ac
#include<cmath>
#include<algorithm>
using namespace std;

//题解：利用st表求区间最大值和区间最小值，相减即为结果

const int MAXN = 5e4+5;
int a[MAXN],top[MAXN][20],bottom[MAXN][20];//top区间最大值，bottom区间最小值
int n,m,t;
void ST_prework() {//初始化
    for(int i = 1;i <= n;i++) top[i][0] = bottom[i][0] = a[i];//初始化边界
    for(int i = 1;i < t;i++) {//先长度，后起点
        for(int j = 1;j <= n-(1<<i)+1;j++) {
            int len = 1<<(i-1);//大区间分成两个小区间，len为小区间长度
            top[j][i] = max(top[j][i-1],top[j+len][i-1]);//求大值
            bottom[j][i] = min(bottom[j][i-1], bottom[j+len][i-1]);//求小值
        }
    }
}
int query_max(int l,int r) {//区间最大值
    int t = log(r-l+1)/log(2);
    return max(top[l][t],top[r-(1<<t)+1][t]);
}
int query_min(int l,int r) {//区间最小值
    int t = log(r-l+1)/log(2);
    return min(bottom[l][t],bottom[r-(1<<t)+1][t]);
}
int main() {
    cin>>n>>m;//全局变量，卡了一万年！！！
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    t = log(n)/log(2)+1;//需要倍增的大小
    ST_prework();
    for(int i = 1;i <= m;i++) {
        int l,r;
        cin>>l>>r;
        cout<<query_max(l,r)-query_min(l,r)<<"\n";
    }
    return 0;
}
