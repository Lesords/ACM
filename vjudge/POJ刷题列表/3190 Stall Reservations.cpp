#include<iostream>//ac
#include<queue>
#include<algorithm>
using namespace std;

//题解；将所有的牛按照吃草的顺序从小到大排序
//然后建立一个优先队列，维护 畜栏的编号和畜栏里的牛结束吃草的时间
//按照 结束吃草的时间 从小到大排序
//然后遍历所有已排序的牛，判断在堆顶的是否能够满足当前牛吃草
//不能，则新建一个畜栏，否则修改堆顶畜栏的信息
//在判断完后可以维护每头牛待的畜栏编号
//注意：结束吃草的时间也在吃草（下一个开始的时间不能等于结束吃草的时间

const int MAXN = 5e4+5;
struct node{
    int id,x,y;
    friend bool operator < (node a,node b) {
        if(a.x!=b.x) return a.x < b.x;//先按照吃草时间排序（从小到大！！！
        return a.y < b.y;
    }
}a[MAXN];
struct stall{
    int id, time;
    friend bool operator < (stall a,stall b) {
        return a.time > b.time;//优先队列，优先时间小的
    }
};
int pos[MAXN];//记录每头牛待的畜栏编号
int main() {
    ios::sync_with_stdio(0);//加速，不加速会tle！！！
    cin.tie(0),cout.tie(0);
    int n,cnt = 0;//cnt为当前畜栏数量
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].x>>a[i].y;
        a[i].id = i;//牛的标号
    }
    sort(a+1,a+1+n);//排序
    priority_queue<stall> q;
    for(int i = 1;i <= n;i++) {
        if(q.empty()) {//若优先队列为空，则直接建新的畜栏
            stall tmp = {++cnt,a[i].y};
            pos[a[i].id] = cnt;//记录当前牛待的畜栏位置
            q.push(tmp);
        }
        else {
            stall last = q.top();//取堆顶的畜栏
            if(a[i].x>last.time) {//不能包含！！！
                //满足条件，则继续更新畜栏信息
                q.pop();//弹出旧的畜栏信息
                last.time = a[i].y;//修改结束时间
                pos[a[i].id] = last.id;//记录当前牛待的畜栏位置
                q.push(last);
            }
            else {
                stall tmp = {++cnt,a[i].y};//不满足条件，则建立新的畜栏
                pos[a[i].id] = cnt;//记录当前牛待的畜栏位置
                q.push(tmp);
            }
        }
    }
    cout<<cnt<<"\n";//畜栏数量
    for(int i = 1;i <= n;i++) {//输出每个牛待的畜栏信息
        cout<<pos[i];
        if(i!=n) cout<<"\n";
    }
    return 0;
}
