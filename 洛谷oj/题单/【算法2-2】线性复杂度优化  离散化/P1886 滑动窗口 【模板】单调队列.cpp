#include<iostream>//ac
#include<deque>
#include<vector>
#include<algorithm>
#define ll long long
using namespace std;

//题解；单调队列，维护满足条件的位置，位置！！！
//对于最大值的队列来说：踢出前面所有小于当前值的数值
//对于最小值的队列来说：踢出前面所有大于当前值的数值
//对于两个队列来说：都需要删除超过范围k的数值

const int MAXN = 1e6+6;
ll a[MAXN];
vector<ll> maxx,minn;//记录最大值和最小值
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n,k;
    deque<ll> up,down;//维护两个单调队列，up是最大值，down是最小值
    cin>>n>>k;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        //删除超过范围k的值
        while(!up.empty()&&i-up.front()+1>k) up.pop_front();
        while(!down.empty()&&i-down.front()+1>k) down.pop_front();
        //删除前面非最优的值
        while(!up.empty()&&a[up.back()]<a[i]) up.pop_back();
        while(!down.empty()&&a[down.back()]>a[i]) down.pop_back();
        up.push_back(i);//入队
        down.push_back(i);
        if(i>=k) {//k区间，则从k开始记录答案
            maxx.push_back(a[up.front()]);//首位置即为最优解
            minn.push_back(a[down.front()]);
        }
    }
    for(ll v:minn) cout<<v<<" ";
    cout<<"\n";
    for(ll v:maxx) cout<<v<<" ";
    return 0;
}
