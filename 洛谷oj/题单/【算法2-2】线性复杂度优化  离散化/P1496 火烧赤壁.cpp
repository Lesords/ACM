#include<iostream>//ac
#include<algorithm>
#define ll long long
using namespace std;

//题解：区间覆盖问题，根据起点和终点排序，结果不受影响！！！
//可以理解为把多出来的范围移到后面去
//然后再判断线段是否重复，删除重复部分即可

const int MAXN = 2e4+5;
int a[MAXN],b[MAXN];
int main() {
    int n;
    cin>>n;
    for(int i = 1;i <= n;i++) cin>>a[i]>>b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);//排序
    ll ans = 0;//有重复的时候可能会爆int
    for(int i = 1;i <= n;i++) {
        ans += b[i]-a[i];//区间和
        //当前不是最后一个时，判断与下一个是否有重复，删除重复部分
        if(i+1<=n&&a[i+1]<b[i]) ans -= b[i]-a[i+1];
    }
    cout<<ans;
    return 0;
}
