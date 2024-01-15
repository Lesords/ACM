#include<iostream>//ac
#include<deque>
#include<algorithm>
using namespace std;

//题解：单调队列，维护较大值的位置
//删除超过范围k的数据 和 小于当前值的数据

const int MAXN = 2e6+5;
int a[MAXN];
int main() {
    int n,k;
    deque<int> d;//维护的是位置
    cin>>n>>k;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
        while(!d.empty()&&i-d.front()+1>k) d.pop_front();//超过范围k
        while(!d.empty()&&a[d.back()]<a[i]) d.pop_back();//删除小于当前值
        d.push_back(i);//入队！！！
        if(i>=k) cout<<a[d.front()]<<"\n";//k区间，从k开始输出
    }
    return 0;
}
