#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 105;

//题解：根据含金量比例从小到大选择即可
//含金量比例为：价值/重量

struct node{
    double wei,val;
    friend bool operator < (node a,node b) {
        return a.val/a.wei > b.val/b.wei;//优先含金量大的
    }
}a[MAXN];
int main() {
    int n,t;
    cin>>n>>t;
    for(int i = 1;i <= n;i++) {
        cin>>a[i].wei>>a[i].val;
    }
    sort(a+1,a+n+1);//排序
    double ans = 0;
    for(int i = 1;i <= n;i++) {
        if(t>=a[i].wei) {//够装
            ans += a[i].val;//价值全加
            t -= a[i].wei;//重量直接减
        }
        else {//不够装
            ans += t*(a[i].val/a[i].wei);//t*含金量
            break;//直接结束
        }
    }
    printf("%.2f",ans);
    return 0;
}
