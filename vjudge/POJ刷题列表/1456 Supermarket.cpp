#include<iostream>//ac
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;

//题解：贪心思路，先按照截止时间从小到大排序
//然后根据堆的数量和价值来建堆
//如果当前的截止时期等于堆的大小，则对比当前的价值和堆顶的价值，取较大值
//否则直接入堆即可（按时间顺序选不会出现小于堆大小的情况

const int MAXN = 1e4+5;
struct node{
    int val,time;
    friend bool operator < (node a, node b) {
        if(a.time!=b.time) return a.time < b.time;//先按照时间从小到大排序
        return a.val > b.val;//然后按照价值从大到小排序
    }
}a[MAXN];
int tree[MAXN],cnt,n;
void down(int pos) {//向下调整
    while(pos*2<=cnt) {//子节点存在则继续
        int tmp = pos*2;
        if(tmp+1<=cnt&&a[tree[tmp+1]].val<a[tree[tmp]].val) tmp++;//右节点更小
        if(a[tree[pos]].val>a[tree[tmp]].val) swap(tree[pos], tree[tmp]);//满足条件则交换
        else break;//否则结束
        pos = tmp;//当前节点移到子节点
    }
}
void up(int pos) {//向上调整
    while(pos>1) {//不为根节点则继续
        int tmp = pos/2;
        if(a[tree[pos]].val<a[tree[tmp]].val) swap(tree[pos],tree[tmp]);//满足条件则交换
        else break;//否则继续
        pos = tmp;
    }
}
int main() {
    while(cin>>n) {
        cnt = 0;
        memset(tree,0,sizeof(tree));
        for(int i = 1;i <= n;i++) {
            cin>>a[i].val>>a[i].time;
        }
        sort(a+1,a+n+1);//先排序
        for(int i = 1;i <= n;i++) {
            if(cnt==0) {//第一个
                tree[++cnt] = i;
                up(cnt);
            }
            else {
                int root = tree[1];//root记录根节点的数值
                if(a[i].time==cnt) {//截止时间等于堆的数量
                    if(a[i].val>a[root].val) {//当前数值更大则更新
                        tree[1] = i;
                        down(1);//向下更新
                    }
                }
                else if(a[i].time>cnt) tree[++cnt] = i,up(cnt);//截止时间未到，记得向上更新！！！
            }
        }
        ll ans = 0;
        for(int i = 1;i <= cnt;i++) {
            ans += a[tree[i]].val;//堆内所有数据即为结果
        }
        cout<<ans<<"\n";
    }
    return 0;
}
