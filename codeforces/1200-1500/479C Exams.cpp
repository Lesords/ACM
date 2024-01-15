#include<iostream>//ac
#include<algorithm>
using namespace std;

//题意：必须按照的顺序是老师规定的考试时间表，只是可以提前考
//题解：按照规定时间和提前时间来排序，然后用个变量记录当前时间
//如果提前时间大于当前时间，则可以选择提前时间，否则只能选择规定时间

const int MAXN = 5005;
struct node{
    int x,y;
    friend bool operator < (node a,node b) {//排序规则
        if(a.x!=b.x) return a.x < b.x;
        return a.y < b.y;
    }
}a[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i].x>>a[i].y;
    sort(a+1,a+n+1);
    int ans = 0;//当前时间
    for(int i = 1;i <= n;i++) {
        if(a[i].y>=ans) ans = a[i].y;//可以提前考
        else ans = a[i].x;//只能按照规定时间考试
    }
    cout<<ans<<"\n";
    return 0;
}
