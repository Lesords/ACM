#include<iostream>//ac
#include<cstdio>
#include<deque>
#include<algorithm>
using namespace std;

//题解：二分答案+前缀和单调队列判定
//单调队列里面维护的是最小的前缀和位置，需满足大于S小于T
//每次用当前位置-队首来判断是否满足条件

//判定的时候每个数值减去平均数k，可以将问题转换为 是否存在区间大于0的情况

const int MAXN = 1e5+5;
int n,s,t,a[MAXN];
double sum[MAXN];//double！！！
bool judge(double val) {
    deque<int> d;//单调队列
    for(int i = 1;i <= n;i++) {//前缀和（注意减平均值val
        sum[i] = sum[i-1] + (double)a[i]-val;
    }
    for(int i = s;i <= n;i++) {//最小的范围是s，所以从s开始
        if(i>=s) {//满足最短范围时
            //队尾若比当前值大，则出队
            while(!d.empty()&&sum[d.back()]>sum[i-s]) d.pop_back();
            d.push_back(i-s);//当前入队（区间最小为s，所以减s）
        }
        //判断队首是否超过t，超过的出队
        while(!d.empty()&&i-d.front()>t) d.pop_front();
        //由于队首的为最小值，所以直接判断差值是否大于0即可
        if(!d.empty()&&sum[i]-sum[d.front()]>=0) return true;
    }
    return false;
}
int main() {
    cin>>n>>s>>t;
    for(int i = 1;i <= n;i++) cin>>a[i];
    double l = -10000,r = 10000,ans = 0;//初始化为值的范围
    while(r-l>=1e-5) {//保留三位小数，所以判断五位
        double mid = (l+r)/2;
        //将左右区间移到mid即可
        if(judge(mid)) ans = mid,l = mid;//满足条件则更新ans
        else r = mid;
    }
    printf("%.3lf",ans);
    return 0;
}
