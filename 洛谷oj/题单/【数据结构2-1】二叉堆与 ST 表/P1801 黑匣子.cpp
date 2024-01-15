#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;
const int MAXN = 2e5+5;

//题解：对顶堆
//建立一个大根堆存储较小值和一个小根堆存储较大值
//由于求k小，所以优先给大根堆存值，查询多小的值，大根堆的大小就为多少
//注意：如果没有添加值，也要维护大根堆的大小！！！

priority_queue<int,vector<int>,greater<int> > up;//小根堆
priority_queue<int> down;//大根堆
int a[MAXN],b[MAXN],cnt,rk;//cnt表示当前已经添加的数据数量，rk为求的第几小
void adjust() {//调整大根堆的大小
    //小于rk，并且小根堆有值时，将小根堆的值移到大根堆中
    while(down.size()<rk&&!up.empty()) down.push(up.top()),up.pop();
    //超过rk，直接移到小根堆中
    while(down.size()>rk) up.push(down.top()),down.pop();
}
void add(int val) {//把值val添加到对顶堆中
    //大根堆为空或者当前值小于大根堆的堆顶
    if(down.empty()||val<down.top()) down.push(val);
    else up.push(val);
    adjust();//调整堆大小（多调整会快点
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);//加速
    int n,m;
    cin>>n>>m;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= m;i++) {
        cin>>b[i];
        rk = i;//更新rk的值
        while(cnt<b[i]) add(a[++cnt]);//数量不满足b[i]，则继续添加值
        adjust();//调整大根堆的大小！！！
        cout<<down.top()<<"\n";
    }
    return 0;
}
