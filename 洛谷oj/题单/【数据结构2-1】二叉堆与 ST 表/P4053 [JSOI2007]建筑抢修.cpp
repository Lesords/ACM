#include<iostream>//ac
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

//题解：不能直接贪心，需要记录历史修理时间！！！
//将数据按照限定时间从小到大排序
//然后判断每个建筑当前时间+修理时间是否足够（即小于限定时间
//若满足，则直接更新花费时间和答案，并将花费时间放入队列中
//若不满足，则在历史花费时间中，寻找一个比当前花费时间大的，若有，则与当前时间替换
//也就是说：若当前不满足，即i位置不满足，那么前i个只有i-1个可修复
//那么我们可以将i-1的修复的时间尽量缩小！！！
//由于前面i-1的限定时间都比当前时间小，也就是说若前面都满足条件，并且存在历史花费时间大于当前花费时间
//那么替换成当前花费时间肯定能满足第i的限定时间
//从数学角度思考，如下：
//sum[i-1] < T[i-1] < T[i] , max(a[1...(i-1)]) > a[i]
//sum[i-1] - max(a[1...(i-1)]) + a[i] < T[i-1] < T[i]
//sum为前缀和，T为限定时间，a为花费时间

const int MAXN = 15e4+5;
struct node{
    ll cost,time;
    friend bool operator < (node a,node b) {
        return a.time < b.time;//时间从小到大排序
    }
}a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].cost>>a[i].time;
    }
    sort(a+1,a+1+n);//排序
    priority_queue<int>q;
    int ans = 0;
    ll nowt = 0;//当前花费的总时间
    for(int i = 1;i <= n;i++) {
        if(nowt+a[i].cost<a[i].time) {//满足条件
            ans++;
            nowt += a[i].cost;//更新时间
            q.push(a[i].cost);//记录历史时间
        }
        else {
            int tmp = q.top();
            if(tmp>a[i].cost) {//若存在历史花费时间比当前花费时间大
                nowt -= tmp;//删除较大值
                nowt += a[i].cost;//保存较小值
                q.pop();//存在才需要pop！！！
                q.push(a[i].cost);//替换成当前花费时间
            }
        }
    }
    cout<<ans;
    return 0;
}
