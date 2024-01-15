#include<iostream>//ac
#include<queue>
#include<algorithm>
#define ll long long
using namespace std;

//题解：先将两个数组从小到大排序
//选择第一个数组的第一个数组和第二个数组的所有数组匹配
//将所有匹配结果放入优先队列中，每次取堆顶，并将对应的位置后移再放入队列中
//取n个即为结果

//注意：因为第二个数组的所有位置的可能性都有了，所以只需要修改第一个数组的位置即可

const int MAXN = 1e5+5;
struct node{
    int x,y;
    ll val;
    friend bool operator < (node a,node b) {
        return a.val > b.val;//优先值小的
    }
};
int a[MAXN],b[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i];
    }
    for(int i = 1;i <= n;i++) {
        cin>>b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);//从小到大排序
    priority_queue<node> q;
    for(int i = 1;i <= n;i++) {//第一组的第一个 加 第二组的所有位置
        q.push({1,i,a[1]+b[i]});
    }
    int cnt = 0;//记录获取的结果数量
    while(cnt<n) {
        node tmp = q.top();
        q.pop();
        cout<<tmp.val<<" ";//直接输出堆顶的值
        cnt++;
        if(tmp.x+1<=n) {//若第一组位置还可移动
            tmp.x++;
            tmp.val = a[tmp.x]+b[tmp.y];//更新对应值
            q.push(tmp);
        }
    }
    return 0;
}
