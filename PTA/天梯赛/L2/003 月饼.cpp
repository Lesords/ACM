#include<iostream>//ac
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1e3+5;
struct node{
    double wei,val,sing;
    friend bool operator < (node a,node b) {
        //先排序单价，然后重量
        if(a.sing!=b.sing) return a.sing > b.sing;
        return a.wei > b.wei;
    }
}a[MAXN];
int main() {
    int n,d;
    cin>>n>>d;
    for(int i = 1;i <= n;i++) cin>>a[i].wei;//wei重量，val为总售价
    for(int i = 1;i <= n;i++) cin>>a[i].val,a[i].sing = a[i].val/a[i].wei;
    //单价 = 总价/重量
    sort(a+1,a+n+1);
    double ans = 0;
    for(int i = 1;i <= n;i++) {//d为还需要的重量
        if(d==0) break;//为0时结束
        if(d>a[i].wei) {//当前全需要
            ans += a[i].val;
            d -= a[i].wei;//减需求
        }
        else {
            ans += a[i].sing*d;//只需要最后的d重量
            break;//结束
        }
    }
    printf("%.2f",ans);//保留两位即可
    return 0;
}
