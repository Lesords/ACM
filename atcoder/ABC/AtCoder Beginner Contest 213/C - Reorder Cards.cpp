#include<iostream>//ac
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<algorithm>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define INF 0x3f3f3f3f
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;

//题解：可以理解为，将所有点尽量向上靠和向左靠
//那么将所有点根据横坐标（或纵坐标）从小到大排序
//然后从头到尾开始记录空行的数量，将对应坐标值减去对应的空行（列）数即可
//需要注意判断一下，当前点和上一个点的坐标相同的情况！！！

const int MAXN = 1e5+5;
const int MOD = 1e9+7;
struct node{
    int x,y,index;//(x,y)为对应坐标，index为下标
}a[MAXN],ans[MAXN];
bool cmp1(node a,node b) {//根据横坐标x排序
    if(a.x==b.x) return a.y < b.y;
    return a.x < b.x;
}
bool cmp2(node a,node b) {//根据纵坐标y排序
    if(a.y==b.y) return a.x < b.x;
    return a.y < b.y;
}
int main() {
    int h,w,n;
    cin>>h>>w>>n;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].x>>a[i].y;
        a[i].index = i;//记录对应下标值
    }
    //两个坐标分别独立计算！！！

    //计算横坐标x
    sort(a+1,a+n+1,cmp1);
    int tmp = 0;//tmp为对应行或列的空行数量
    for(int i = 1;i <= n;i++) {
        int now = a[i].index;
        if(i==1) tmp = a[i].x-1;
        else {
            if(a[i].x!=a[i-1].x) {//忽略相等情况
                tmp += a[i].x-a[i-1].x-1;
            }
        }
        ans[now].x = a[i].x-tmp;//扣除对应的空行
    }
    //计算纵坐标y
    sort(a+1,a+n+1,cmp2);
    tmp = 0;
    for(int i = 1;i <= n;i++) {
        int now = a[i].index;
        if(i==1) tmp = a[i].y-1;
        else {
            if(a[i].y!=a[i-1].y) {//忽略相等情况
                tmp += a[i].y-a[i-1].y-1;
            }
        }
        ans[now].y = a[i].y-tmp;//扣除对应的空列
    }
    for(int i = 1;i <= n;i++) cout<<ans[i].x<<" "<<ans[i].y<<"\n";
	return 0;
}

