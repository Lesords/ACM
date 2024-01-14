#include<iostream>//ac
#include<cstdio>
#include<algorithm>
#define INF 0x3f3f3f3f
using namespace std;

//题解：双指针求区间最大值
//利用l表示当前区间的左端点位置，r表示当前区间右端点的位置
//每次累加r位置的结果，判断当前区间值是否大于结果，若大于结果，则更新
//如果当前区间和小于0，表示当前区间对于后面的数字只会有负贡献
//所以重新设置区间，将l和r一起设为当前的后一位，并将区间和设为0
//注意：区间和有负数，所以初始化结果需为-INF

const int MAXN = 1e5+5;
int a[MAXN];
int main() {
    int t;
    scanf("%d",&t);
    for(int cas = 1;cas <= t;cas++) {
        int n;
        scanf("%d",&n);
        for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
        int l = 1,r = 1,sum = 0;//表示当前状态
        int ans = -INF,ans_l  = 0,ans_r = 0;//记录结果
        while(r<=n) {//r表示还没计算的，所以为n的时候也需要计算一次！！！
            sum += a[r];
            if(sum>ans) {//大于结果，则更新对应信息
                ans = sum;
                ans_l = l,ans_r = r;
            }
            r++;//后移一位
            if(sum<0) {//若区间和小于0，则修改区间起点
                sum = 0;
                l=r;//修改起点位置
            }
        }
        printf("Case %d:\n",cas);
        printf("%d %d %d\n", ans,ans_l,ans_r);
        if(cas!=t) puts("");
    }
    return 0;
}
/*
2
5
-1 0 -8 -9 -11
5
0 -1 0 -1 -5
5
1 2 -11 2 1
*/
