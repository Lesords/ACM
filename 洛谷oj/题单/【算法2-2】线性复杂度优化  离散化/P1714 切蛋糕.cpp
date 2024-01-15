#include<iostream>//ac
#include<deque>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define INF 0x3f3f3f3f
using namespace std;

//题解：单调队列
//队列内维护对应的数值的位置
//由于可能出现开头位置即为最大值，所以需要添加一个边界0
//队首中超过位置m的弹出，因为区间长度为m，但是前缀和左区间为闭区间(相减)，所以包括m
//队尾的前缀和大于当前值，那么弹出
//因为要想使区间和最大，那么前面的前缀和必须取较小值！！！
//最后更新答案

const int MAXN = 5e5+5;
int n,m;
int a[MAXN], sum[MAXN];//a为原数组，sum为前缀和数组
int main() {
//    freopen("P1714_2.in", "r", stdin);
    fast;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        sum[i] = a[i]+sum[i-1];
    }
    deque<int> q;
    q.push_back(0);//边界位置
    int ans = -INF;//会出现负数情况
    for(int i = 1;i <= n;i++) {
        //越界，弹出，q.front()是左边界（开区间），所以可以为m
        while(!q.empty()&&i-q.front()>m) q.pop_front();
        //队尾大于当前值，弹出（尽量小）
        while(!q.empty()&&sum[q.back()]>=sum[i]) q.pop_back();
        q.push_back(i);//记录当前值
        ans = max(ans, sum[i]-sum[q.front()]);//更新结果
    }
    cout<<ans<<"\n";
    return 0;
}
/*
10 8
500 -448 -431 86 -41 190 -46 -104 233 1
500
*/
