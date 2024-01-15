#include<iostream>//ac
#include<deque>
#include<algorithm>
using namespace std;

//题解：单调队列，可手写或用deque
//单调队列维护对当前作用的值的位置（位置！！！
//每次把超出范围的值踢出队列，然后输出队首值（不包括当前位置
//然后维护有用的值，把大于当前值的位置全部踢出队列，然后再将当前数据入队

const int MAXN = 2e6+5;
int a[MAXN];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);//加速
    int n,m;
    deque<int> q;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        if(i==1) {//特判首位置，前面为空
            cout<<"0\n";
            q.push_back(i);//入队
            continue;
        }
        while(q.size()>1&&i-q.front()>m) q.pop_front();//删除超过范围数据（保留一个
        cout<<a[q.front()]<<"\n";//先输出数据，再更新
        while(!q.empty()&&a[q.back()]>a[i]) q.pop_back();//删除比当前大的所有数据
        q.push_back(i);//入队
    }
    return 0;
}
